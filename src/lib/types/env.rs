use super::Type;

use std::collections::HashMap;

#[derive(Debug, Clone, PartialEq)]
pub struct Env {
    pub parent: Option<Box<Env>>,
    pub symbols: HashMap<String, Vec<Type>>,
}

impl Env {
    pub fn new(parent_env: Option<Box<Env>>) -> Self {
        Self { parent: None, symbols: HashMap::new() }
    }
}
