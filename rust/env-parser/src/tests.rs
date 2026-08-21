use crate::parse_env;

macro_rules! hashmap {
    ($($key:ident=$value:expr,)*) => {
        std::collections::HashMap::from([$((stringify!($key).to_string(), $value.to_string()),)*])
    };
}

#[test]
fn parsing() {
    let env = parse_env("testdata/.env").unwrap();
    let expected = hashmap! {
        DB_HOST="localhost",
        DB_PORT="5432",
        API_KEY="my_api_key",
        LOG_FILE="app.log",
        KEY="VALUE",
        empty="",
        another="value=more",
        quoted="value",
        newlines="value\\nwith\\nnewlines",
        comment="value#notacomment",
        nonascii="value🍪",
        duplicate="2",
    };
    for (k, v) in expected {
        if !env.contains_key(&k) {
            panic!("expected key {k} not found");
        }
        if env[&k] != v {
            panic!("expected {k}={v}, got {k}={}", env[&k]);
        }
    }
}
