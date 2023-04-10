use rustyline::error::ReadlineError;
use rustyline::{DefaultEditor, Result};

fn main() -> Result<()> {
    let mut editor = DefaultEditor::new()?;

    #[cfg(feature = "with-file-history")]
    if editor.load_history("history.txt").is_err() {
        println!("No previous history.");
    }

    println!("Lix v0.0.1");
    println!("Press CTRL-C to exit\n");

    loop {
        let readline = editor.readline("lix > ");

        match readline {
            Ok(line) => {
                match editor.add_history_entry(line.as_str()) {
                    Ok(_) => println!("Line: {}", line),
                    Err(err) => {
                        println!("Error adding line: {}, to the history.", line);
                        println!("Aborting with error: {}", err);
                        break
                    }
                }
                
            },
            Err(ReadlineError::Interrupted) => {
                println!("CTRL-C");
                break
            },
            Err(ReadlineError::Eof) => {
                println!("CTRL-D");
                break
            },
            Err(err) => {
                println!("Error: {:?}", err);
                break
            }
        }
    }

    #[cfg(feature = "with-file-history")]
    editor.save_history("history.txt");
    Ok(())

}
