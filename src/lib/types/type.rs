use super::FuncType;

#[derive(Debug, Clone, PartialEq)]
pub enum Type {
    NoneType,
    Num(i64),
    Float(f64),
    String(String),
    Error(String),
    Symbol(String),
    Function(FuncType),
    Sexpr(Vec<Type>),
    Qexpr(Vec<Type>),
}
