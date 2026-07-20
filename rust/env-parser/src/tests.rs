use crate::parse_env;

macro_rules! hashmap {
    ($($key:expr => $value:expr,)*) => {
        std::collections::HashMap::from([$(($key, $value),)*])
    };
}

#[test]
fn parsing() {
    let env = parse_env("testdata/.env").unwrap();
    let expected = hashmap! {
        "DB_HOST".to_string() => "localhost".to_string(),
        "DB_PORT".to_string() => "5432".to_string(),
        "API_KEY".to_string()=>"my_api_key".to_string(),
        "LOG_FILE".to_string()=>"app.log".to_string(),
    };
    assert_eq!(env, expected);
}
