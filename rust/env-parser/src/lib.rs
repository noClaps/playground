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
            line.split_once('=')
                .map(|(l, r)| (l.trim().to_string(), r.trim().to_string()))
        })
        .collect())
}
