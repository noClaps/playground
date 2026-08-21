//! https://corrode.dev/blog/ugly/

use std::{collections::HashMap, fs, io};

#[cfg(test)]
mod tests;

pub fn parse_env(path: &str) -> Result<HashMap<String, String>, io::Error> {
    Ok(fs::read_to_string(path)?
        .lines()
        .filter_map(|line| {
            // skip comments
            if line.starts_with('#') {
                return None;
            }
            let (k, mut v) = line
                .split_once('=')
                .map(|(l, r)| (l.trim().to_string(), r.trim().to_string()))?;
            // empty keys are not valid
            if k.is_empty() {
                return None;
            }
            if v.starts_with('"') && v.ends_with('"') {
                // remove quotes from quoted value
                v = v[1..v.len() - 1].to_string();
            } else if v.contains(char::is_whitespace) {
                // if not quoted, dont capture anything after first whitespace
                v = v.split_whitespace().next().unwrap().to_string();
            }
            Some((k, v))
        })
        .collect())
}
