BEGIN TRANSACTION;

/* Create board designed table
* => designed true 3NF format
*/
CREATE TABLE IF NOT EXISTS "designed_dev_board"
(
	[code_board]     TEXT  NOT NULL  PRIMARY KEY,   -- dev board code is unique
	[descript]       TEXT ,                -- string descript about board is constrain with unique board
	[hardware_limit] TEXT DEFAULE '{}'     -- JSON descript limit of unique board
);


/*
* Create logic code block will implement both UI and embedded
* => designed true 3NF format
*/
CREATE TABLE IF NOT EXISTS "logic_code_block"
(
	[code_logic]       TEXT NOT NULL  PRIMARY KEY,   -- Logic code block use to link design UI controller in app with implemented code logic block in dev board 
	[descript]	   TEXT ,                 -- string descript about a code logic block implement in both UI app and embedded firmware
	[hardware_require] TEXT DEFAULT '{}'      -- JSON descript required hardware for a logic code block will inplement in devboard
);

/*
* Create table link available logic code block
* => designed true 3NF format
*/
CREATE TABLE IF NOT EXISTS "link_lcb_with_dev_board"
(
	[code_board]  TEXT  NOT NULL,            -- devboard code
	[code_logic]  TEXT  NOT NULL,            -- logic block code
	[descript]    TEXT,            -- descript about this relationship
	PRIMARY KEY ([code_board], [code_logic]) -- unique pair available lcb suitable with a dev board
    	FOREIGN KEY ([code_board]) REFERENCES designed_dev_board([code_board]) ON DELETE CASCADE,
	FOREIGN KEY ([code_logic]) REFERENCES logic_code_block([code_logic]) ON DELETE CASCADE
);


COMMIT;
