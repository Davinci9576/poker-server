const mysql = require("mysql2");

const db = mysql.createConnection({
    host: process.env.MYSQLHOST,
    user: process.env.MYSQLUSER,
    password: process.env.MYSQLPASSWORD,
    database: process.env.MYSQLDATABASE,
    port: process.env.MYSQLPORT
});

db.connect((err) => {
    if(err){
        console.log("Database connection failed");
        console.log(err);
        return;
    }

    console.log("MYSQL connected!");
});

module.exports = db;