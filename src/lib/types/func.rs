use super::{Type, Env};

pub struct FuncType {
    pub formals: Box<Type>,
    pub body: Box<Type>,
    pub env: Box<Env>,
    pub builtin: Option<Box<dyn Fn(&Box<Env>, &Type) -> () + 'static>>,
}

impl FuncType {
    pub fn new(args: Box<Type>, block: Box<Type>) -> Self {
        Self { 
            formals: args,
            body: block,
            env: Box::new(Env::new(None)),
            builtin: None
        }
    }
}
