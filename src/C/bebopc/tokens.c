#include "../../../inc/_h/numtypes.h"
#include "../../../inc/_h/DTypes.h"
#include "../../../inc/_h/bebopc/keysTokens.h"
#include "../../../inc/_h/bebopc/ObjectTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define little_endian -1
#define big_endian     0

char ENDIAN = little_endian;

#define _var_type 0x00
#define _key_type 0x01
#define _err_type 0x02

#define TOK_INIT 256
#define word_i_size 128

#define _utf1byte 0x01
#define _utf2byte 0x02
#define _utf3byte 0x03
#define _utf4byte 0x04

#define invalidChar 0xFFFFFFFF

#define jmp goto

typedef enum LexicalErrors {
    _invchar,
    _reallword,
} LexicalErros;

const string LexicalErrors_messages[] = {
    "invalid charactere",
    "error when relocating string"
};

char verifyInterruption(uint32_t chr, char charactere_size){
    char chars_8bits[] = "+-*%/=^|&~`!?@#$(){}[],.:;<>\\'\"\n";
    char chars_16bits[] = "¹²³£¢¬°´®ŧøþªÆÐŊĦˀĸŁºˇ«»©µ· ";
    char chars_24bits[] = " ← ↓ → „ “ ” •   ";

    if(charactere_size == _utf1byte){
        for(uint8_t i = 0; i < sizeof(chars_8bits) - 1; i++)
            if(*(chars_8bits + i) == (uint8_t)chr)
                return 1;

        return 0;
    }

    if(charactere_size == _utf2byte){
        uint16_t *buffer_16bits = (uint16_t*)chars_16bits;
        uint16_t adapt_char = (uint16_t)(chr << 8);
        adapt_char |= (uint16_t)(chr >> 8);

        for(uint8_t i = 0; i < sizeof(chars_16bits) / 2; i++)
            if(adapt_char == *(buffer_16bits + i))
                return 1;

        return 0;
    }

    uint32_t *buffer_24bits = (uint32_t*)chars_24bits;

    uint32_t adapt_char = 0x00000000;
    adapt_char |= chr << 24;
    adapt_char |= (chr & 0x0000FF00) << 8;
    adapt_char |= (chr & 0x00FF0000) >> 8;
    adapt_char >>= 8;

    for(uint8_t i = 0; i < sizeof(chars_24bits) / 4; i++)
        if(adapt_char == *(buffer_24bits + i) >> 8)
            return 1;

    return 0;
}


uint32_t offsetfile(string file, uint64_t *index, char *charactere_size, uint8_t chr){
    uint32_t charactere = 0;

    if(!(chr & 0x80)){
        (*index)++;
        *(charactere_size) = _utf1byte;
        return (uint32_t)chr;
    }

    if((chr >> 5) == 0x06){
        *(charactere_size) = _utf2byte;
        charactere = ((uint32_t)(*(file + *index) & 0xFF) << 8) | (uint8_t)(*(file + (*index + 1)));
        (*index) += 2;
        return charactere;
    }

    if((chr >> 4) == 0x0E){
        *(charactere_size) = _utf3byte;
        charactere = ((uint32_t)(chr & 0xFF) << 16);
        charactere |= (uint16_t)(*(file + (*index + 1)) & 0xFF) << 8;
        charactere |= (uint8_t)(*(file + (*index + 2)) & 0xFF);
        (*index) += 3;
        return charactere;
    }

    if((chr >> 3) == 0x1E){
        *(charactere_size) = _utf4byte;
        charactere = ((uint32_t)(chr & 0xFF) << 24);
        charactere |= (uint32_t)(*(file + (*index + 1)) & 0xFF) << 16;
        charactere |= (uint16_t)(*(file + (*index + 2)) & 0xFF) << 8;
        charactere |= (uint8_t)(*(file + (*index + 3)) & 0xFF);
        (*index) += 4;
        return charactere;
    }

    return (uint32_t)invalidChar;
}

unsigned int stringCode(char *str, int size){
    unsigned int i = 0, code = 0;

    while(*(str + i)){
        code += *(str + i);

        if(i > 0)
            code += *(str + i) ^ *(str + i - 1);

        i++;
    }

    return code + size * (*(str) ^ *(str + size - 1)) + (*(str) & *(str + size - 1)) * *(str);
}

ident_or_object_or_method* is_a_keyword_quest(string word, uint64_t size){
    if (size < if_.l || size > remove_f_id_.l) return NULL;

    unsigned int code = stringCode(word, size);

    if(code < i32_.code || code > to_float_.code)
        return NULL;

    for(int i = 0; i < sizeof(objects) / sizeof(ident_or_object_or_method*); i++){
        if((code == objects[i]->code) && (size == objects[i]->l)){
            for(int j = 0; i < size; j++)
                if(*(word + j) != *(objects[i]->k + j))
                    jmp TEST_METHOD;

            return (ident_or_object_or_method*) objects[i];
        }
    }

    TEST_METHOD:

    for(int i = 0; i < sizeof(methods) / sizeof(ident_or_object_or_method*); i++){
        if((code == methods[i]->code) && (size == methods[i]->l)){
            for(int j = 0; i < size; j++)
                if(*(word + j) != *(methods[i]->k + j))
                    jmp TEST_IDENTIFIER;

            return (ident_or_object_or_method*) methods[i];
        }
    }

    TEST_IDENTIFIER:

    for(int i = 0; i < sizeof(identifiers) / sizeof(ident_or_object_or_method*); i++){
        if((code == identifiers[i]->code) && (size == identifiers[i]->l)){
            for(int j = 0; j < size; j++)
                if(*(word + j) != *(identifiers[i]->k + j))
                    return NULL;

            return (ident_or_object_or_method*) identifiers[i];
        }
    }

    return NULL;
}


void endian_buffer_from_uint32_tptr(uint32_t *u32_ptr){
    uint32_t endian_num = 0xAABBCCFF;

    if (*((uint8_t*) &endian_num) == 0xAA) return;

    uint8_t *buffer = (uint8_t*)u32_ptr;
    uint8_t temp = *(buffer);

    *(buffer) = *(buffer + 3);
    *(buffer + 3) = temp;

    temp = *(buffer + 1);

    *(buffer + 1) = *(buffer + 2);
    *(buffer + 2) = temp;

    return;
}


Tokens lexicalAnalyzer(string file, uint64_t srcsize){
    Tokens tokens = { TOK_INIT, 0, (TOK*) malloc(TOK_INIT) };

    uint32_t charactere = 0;
    uint64_t character_count = 0, word_size = word_i_size;
    string error_message = NULL;

    uint8_t *buffer = NULL;
    int8_t error_code = -1;

    char charactere_size = 0;
    char end = 0;

    string word = (string) malloc(word_i_size + 1);

    for(uint64_t i = 0; i < srcsize;){
        if (*(file + i) == ' ') { i++; jmp END; }

        charactere = offsetfile(file, &i, &charactere_size, *(file + i));

        if(charactere == invalidChar || charactere_size == _utf4byte){
            error_message = LexicalErrors_messages[_invchar];
            error_code = _invchar;

            jmp PROCESS_ERROR;
        }

        if(charactere_size <= _utf3byte){
            char res = verifyInterruption(charactere, charactere_size);

            if(res && charactere_size == _utf3byte){
                error_message = LexicalErrors_messages[_invchar];
                error_code = _invchar;

                jmp PROCESS_ERROR;
            }

            if (res) jmp INTERRUPTION;
        }

        if((character_count + charactere_size) >= word_size){
            word_size *= 2;
            string new_word = (string)realloc(word, word_size);

            if(new_word == NULL){
                error_message = LexicalErrors_messages[_reallword];
                error_code = _reallword;

                jmp PROCESS_ERROR;
            }

            word = new_word;
        }

        if(ENDIAN == little_endian)
            endian_buffer_from_uint32_tptr(&charactere);

        uint8_t *auxiliary_ptr = (uint8_t*) &charactere + (_utf4byte - charactere_size);

        memcpy(word + character_count, auxiliary_ptr, charactere_size);
        character_count += charactere_size;

        jmp END;

        INTERRUPTION:
            if(!character_count)
                jmp VERIFY_INTERRUPTION_CHAR;

            *(word + character_count) = '\0';

            printf("word: %s\n", word);

            tokens.toks[tokens.len].value.key_type.keyptr = is_a_keyword_quest(word, character_count);

            if(tokens.toks[tokens.len].value.key_type.keyptr == NULL)
                printf("not is a keyword\n");

            else {
                printf("key.string: %s\n", tokens.toks[tokens.len].value.key_type.keyptr->k);
                printf("key.code: %d\n", tokens.toks[tokens.len].value.key_type.keyptr->code);
                printf("key.length: %d\n", tokens.toks[tokens.len].value.key_type.keyptr->l);
                printf("key.type: %d\n\n", tokens.toks[tokens.len].value.key_type.keyptr->tkey);

                tokens.len++;
            }

            if(word_size > word_i_size){
                word_size = word_i_size;
                string new_word = (string) realloc(word, word_size);

                if(new_word == NULL){
                    error_message = LexicalErrors_messages[_reallword];
                    error_code = _reallword;

                    jmp PROCESS_ERROR;
                }

                word = new_word;
            }

            character_count = 0;

        VERIFY_INTERRUPTION_CHAR:
            if (end) jmp END;

            jmp END;


        PROCESS_ERROR:
            printf("ERROR[%d]: %s\n", error_code, error_message);
            free(word);
            free(tokens.toks);
            tokens.allsize = error_code;
            tokens.toks = NULL;

            return tokens;

        END:
            if (!(*(file + i)) && !end && character_count) { end = 1; jmp INTERRUPTION; }
    }

    free(word);
    free(tokens.toks);
}

int main(){
    string file = ".:;Hello";
    Tokens tokens = lexicalAnalyzer(file, strlen(file));

    return 0;
}
