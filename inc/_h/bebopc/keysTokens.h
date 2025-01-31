#ifndef KEYSTOKENS_H
#define KEYSTOKENS_H

#define IDENT 0
#define OBJECT 1
#define FN 2

typedef struct ident_or_object_or_method {
    const char   *k;
    unsigned int  l;
    unsigned int  code;
    unsigned char tkey;
} ident_or_object_or_method;


typedef enum BebopKeys {
    __if_ = 10332,
    __elif_ = 10557,
    __else_ = 10688,
    _switch_ = 11957,
    _match_ = 11953,
    _for_ = 10421,
    _while_ = 12692,
    _loop_ = 10956,
    _break_ = 10219,
    _continue_ = 10638,
    _case_ = 10081,
    _default_ = 10933,
    _return_ = 12088,
    _struct_ = 13664,
    _enum_ = 10732,
    _fn_ = 10640,
    _import_ = 11020,
    _imut_ = 10672,
    _mthd_ = 11430,
    _contract_ = 10639,
    _let_ = 11223,
    _i8_ = 4604,
    _i16_ = 3948,
    _i32_ = 3930,
    _i64_ = 3947,
    _i128_ = 4885,
    _u8_ = 6020,
    _u16_ = 6580,
    _u32_ = 6118,
    _u64_ = 6571,
    _u128_ = 6277,
    _char_ = 10223,
    _f32_ = 4009,
    _f64_ = 4208,
    _str_ = 13471,
    _null_ = 12383,
    _none_ = 11489,
    __compiler_ = 9314,
    __define_ = 7771,
    __if__ = 7192,
    __elif__ = 7533,
    __else__ = 7485,
    __end_ = 7181,
    _IO_ = 5499,
    _File_ = 5345,
    _Buffer_ = 5346,
    _HashMap_ = 5858,
    _String_ = 6592,
    _Set_ = 7128,
    _List_ = 5874,
    _Type_ = 6401,
    _new_ = 11654,
    _from_ = 10731,
    _push_ = 11334,
    _foreach_ = 10696,
    _copy_ = 10202,
    _offset_ = 11978,
    _remove_f_id_ = 12653,
    _remove_f_v_ = 14390,
    _include_ = 11087,
    _length_ = 11974,
    _capacity_ = 10747,
    _resize_ = 11861,
    _wrt_ = 14173,
    _wrtln_ = 12867,
    _rdln_ = 11748,
    _rdchar_ = 13692,
    _open_ = 12711,
    _write_ = 12742,
    _read_file_ = 12251,
    _read_line_ = 12247,
    _close_ = 10235,
    _to_string_ = 12931,
    _to_integer_ = 14330,
    _to_float_ = 14492,
} BebopKeys;


const ident_or_object_or_method if_ = {"if", sizeof("if") - 1, __if_, IDENT};
const ident_or_object_or_method elif_ = {"elif", sizeof("elif") - 1, __elif_, IDENT};
const ident_or_object_or_method else_ = {"else", sizeof("else") - 1, __else_, IDENT};
const ident_or_object_or_method switch_ = {"switch", sizeof("switch") - 1, _switch_, IDENT};
const ident_or_object_or_method match_ = {"match", sizeof("match") - 1, _match_, IDENT};

const ident_or_object_or_method for_ = {"for", sizeof("for") - 1, _for_, IDENT};
const ident_or_object_or_method while_ = {"while", sizeof("while") - 1, _while_, IDENT};
const ident_or_object_or_method loop_ = {"loop", sizeof("loop") - 1, _loop_, IDENT};

const ident_or_object_or_method break_ = {"break", sizeof("break") - 1, _break_, IDENT};
const ident_or_object_or_method continue_ = {"continue", sizeof("continue") - 1, _continue_, IDENT};
const ident_or_object_or_method case_ = {"case", sizeof("case") - 1, _case_, IDENT};
const ident_or_object_or_method default_ = {"default", sizeof("default") - 1, _default_, IDENT};
const ident_or_object_or_method return_ = {"return", sizeof("return") - 1, _return_, IDENT};

const ident_or_object_or_method struct_ = {"struct", sizeof("struct") - 1, _struct_, IDENT};
const ident_or_object_or_method enum_ = {"enum", sizeof("enum") - 1, _enum_, IDENT};

const ident_or_object_or_method fn_ = {"fn", sizeof("fn") - 1, _fn_, IDENT};
const ident_or_object_or_method import_ = {"import", sizeof("import") - 1, _import_, IDENT};
const ident_or_object_or_method imut_ = {"imut", sizeof("imut") - 1, _imut_, IDENT};
const ident_or_object_or_method mthd_ = {"mthd", sizeof("mthd") - 1, _mthd_, IDENT};
const ident_or_object_or_method contract_ = {"contract", sizeof("contract") - 1, _contract_, IDENT};
const ident_or_object_or_method let_ = {"let", sizeof("let") - 1, _let_, IDENT};

const ident_or_object_or_method i8_ = {"i8", sizeof("i8") - 1, _i8_, IDENT};
const ident_or_object_or_method i16_ = {"i16", sizeof("i16") - 1, _i16_, IDENT};
const ident_or_object_or_method i32_ = {"i32", sizeof("i32") - 1, _i32_, IDENT};
const ident_or_object_or_method i64_ = {"i64", sizeof("i64") - 1, _i64_, IDENT};
const ident_or_object_or_method i128_ = {"i128", sizeof("i128") - 1, _i128_, IDENT};
const ident_or_object_or_method u8_ = {"u8", sizeof("u8") - 1, _u8_, IDENT};
const ident_or_object_or_method u16_ = {"u16", sizeof("u16") - 1, _u16_, IDENT};
const ident_or_object_or_method u32_ = {"u32", sizeof("u32") - 1, _u32_, IDENT};
const ident_or_object_or_method u64_ = {"u64", sizeof("u64") - 1, _u64_, IDENT};
const ident_or_object_or_method u128_ = {"u128", sizeof("u128") - 1, _u128_, IDENT};
const ident_or_object_or_method char_ = {"char", sizeof("char") - 1, _char_, IDENT};
const ident_or_object_or_method f32_ = {"f32", sizeof("f32") - 1, _f32_, IDENT};
const ident_or_object_or_method f64_ = {"f64", sizeof("f64") - 1, _f64_, IDENT};
const ident_or_object_or_method _str = {"str", sizeof("str") - 1, _str_, FN};

const ident_or_object_or_method null_ = {"null", sizeof("null") - 1, _null_, IDENT};
const ident_or_object_or_method none_ = {"none", sizeof("none") - 1, _none_, IDENT};

const ident_or_object_or_method _compiler_ = {"_compiler", sizeof("_compiler") - 1, __compiler_, IDENT};
const ident_or_object_or_method _define_ = {"_define", sizeof("_define") - 1, __define_, IDENT};
const ident_or_object_or_method _if_ = {"_if", sizeof("_if") - 1, __if__, IDENT};
const ident_or_object_or_method _elif_ = {"_elif", sizeof("_elif") - 1, __elif_, IDENT};
const ident_or_object_or_method _else_ = {"_else", sizeof("_else") - 1, __else_, IDENT};
const ident_or_object_or_method _end_ = {"_end", sizeof("_end") - 1, __end_, IDENT};



const ident_or_object_or_method IO_ = {"IO", sizeof("IO") - 1, _IO_, OBJECT};
const ident_or_object_or_method File_ = {"File", sizeof("File") - 1, _File_, OBJECT};
const ident_or_object_or_method Buffer_ = {"Buffer", sizeof("Buffer") - 1, _Buffer_, OBJECT};
const ident_or_object_or_method HashMap_ = {"HashMap", sizeof("HashMap") - 1, _HashMap_, OBJECT};
const ident_or_object_or_method String_ = {"String", sizeof("String") - 1, _String_, OBJECT};
const ident_or_object_or_method Set_ = {"Set", sizeof("Set") - 1, _Set_, OBJECT};
const ident_or_object_or_method List_ = {"List", sizeof("List") - 1, _List_, OBJECT};
const ident_or_object_or_method Type_ = {"Type", sizeof("Type") - 1, _Type_, OBJECT};



const ident_or_object_or_method new_ = {"new", sizeof("new") - 1, _new_, FN};
const ident_or_object_or_method from_ = {"from", sizeof("from") - 1, _from_, FN};
const ident_or_object_or_method foreach_ = {"foreach", sizeof("foreach") - 1, _foreach_, FN};
const ident_or_object_or_method push_ = {"push", sizeof("push") - 1, _push_, FN};
const ident_or_object_or_method copy_ = {"copy", sizeof("copy") - 1, _copy_, FN};
const ident_or_object_or_method offset_ = {"offset", sizeof("offset") - 1, _offset_, FN};
const ident_or_object_or_method remove_f_id_ = {"remove_f_id", sizeof("remove_f_id") - 1, _remove_f_id_, FN};
const ident_or_object_or_method remove_f_v_ = {"remove_f_v", sizeof("remove_f_v") - 1, _remove_f_v_, FN};
const ident_or_object_or_method include_ = {"include", sizeof("include") - 1, _include_, FN};
const ident_or_object_or_method length_ = {"length", sizeof("length") - 1, _length_, FN};
const ident_or_object_or_method capacity_ = {"capacity", sizeof("capacity") - 1, _capacity_, FN};
const ident_or_object_or_method resize_ = {"resize", sizeof("resize") - 1, _resize_, FN};

const ident_or_object_or_method wrt_ = {"wrt", sizeof("wrt") - 1, _wrt_, FN};
const ident_or_object_or_method wrtln_ = {"wrtln", sizeof("wrtln") - 1, _wrtln_, FN};
const ident_or_object_or_method rdln_ = {"rdln", sizeof("rdln") - 1, _rdln_, FN};
const ident_or_object_or_method rdchar_ = {"rdchar", sizeof("rdchar") - 1, _rdchar_, FN};

const ident_or_object_or_method open_ = {"open", sizeof("open") - 1, _open_, FN};
const ident_or_object_or_method write_ = {"write", sizeof("write") - 1, _write_, FN};
const ident_or_object_or_method read_file_ = {"read_file", sizeof("read_file") - 1, _read_file_, FN};
const ident_or_object_or_method read_line_ = {"read_line", sizeof("read_line") - 1, _read_line_, FN};
const ident_or_object_or_method close_ = {"close", sizeof("close") - 1, _close_, FN};

const ident_or_object_or_method to_string_ = {"to_string", sizeof("to_string") - 1, _to_string_, FN};
const ident_or_object_or_method to_integer_ = {"to_integer", sizeof("to_integer") - 1, _to_integer_, FN};
const ident_or_object_or_method to_float_ = {"to_float", sizeof("to_float") - 1, _to_float_, FN};



const ident_or_object_or_method* identifiers[] = {
    &if_, &elif_, &else_, &switch_, &match_,
    &for_, &while_, &loop_, &break_, &continue_,
    &case_, &default_, &return_, &struct_, &enum_,
    &fn_, &import_, &imut_, &mthd_, &contract_,
    &let_, &i8_, &i16_, &i32_, &i64_,
    &i128_, &u8_, &u16_, &u32_, &u64_,
    &u128_, &char_, &f32_, &f64_, &_str,
    &null_, &none_, &_compiler_, &_define_, &_if_,
    &_elif_, &_else_, &_end_
};

const ident_or_object_or_method* objects[] = {
    &IO_,
    &File_,
    &Buffer_,
    &HashMap_,
    &String_,
    &Set_,
    &List_,
    &Type_
};

const ident_or_object_or_method* methods[] = {
    &new_, &from_, &push_, &foreach_, &copy_, 
    &offset_, &remove_f_id_, &remove_f_v_, &include_, &length_,
    &capacity_, &resize_, &wrt_, &wrtln_, &rdln_,
    &rdchar_, &open_, &write_, &read_file_, &read_line_,
    &close_, &to_string_, &to_integer_, &to_float_
};

#endif // KEYSTOKENS_H