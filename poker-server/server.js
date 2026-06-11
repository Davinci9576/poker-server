const bcrypt = require("bcrypt");
const express = require("express");
const db=require("./db");
const app = express();

app.use(express.json());

// GET → get leaderboard
app.get("/leaderboardMoney", (req, res) => {
    db.query(
        "SELECT username, balance FROM users ORDER BY balance DESC",
        (err, results)=>{
            if(err){
                return res.status(500).json({
                    error: "Database error"
                });
            }
            res.json(results);
        }
    );
});

app.get("/leaderboardWins", (req, res) => {
    db.query(
        "SELECT username, wins FROM users ORDER BY wins DESC",
        (err, results)=>{
            if(err){
                return res.status(500).json({
                    error: "Database error"
                });
            }
            res.json(results);
        }
    );
});

app.get("/leaderboardWinrate", (req, res) => {
    db.query(
        "SELECT username, winrate FROM users ORDER BY winrate DESC",
        (err, results)=>{
            if(err){
                return res.status(500).json({
                    error: "Database error"
                });
            }
            res.json(results);
        }
    );
});
app.post("/register", async (req, res) => {

    const { username, password } = req.body;
    try{
        const hashedPassword=await bcrypt.hash(password, 10);
    
    db.query(
        "INSERT INTO users (username, password) VALUES(?, ?)",
        [username, hashedPassword],
        (err, result)=>{
            if(err){
                console.log(err);
                return res.json({
                    success: false
                });
            }
            res.json({
                success: true
            });
        }
    );
}catch(err){
    console.log(err);
    res.json({
        success: false
    });
}
});
app.post("/updateProgress", (req, res)=>{
    const{
        username,
        balance,
        wins,
        losses,
        winrate
    }=req.body;
    db.query(
        `UPDATE users
         SET balance = ?,
             wins = ?,
             losses = ?,
             winrate = ?
         WHERE username = ?`,
        [
            balance,
            wins,
            losses,
            winrate,
            username
        ],
        (err, result)=>{
            if(err){
                console.log(err);
                return res.json({
                    success: false
                });
            }
            res.json({
                success: true
            });
        }
    );
});
app.post("/login", (req, res)=>{
    const {username, password}=req.body;
    db.query(
        "SELECT*FROM users WHERE username=?",
        [username],
        async(err, results)=>{
            if(err){
                console.log(err);
                return res.json({
                    success: false
                });
            }
            if(results.length===0){
                return res.json({
                    success:false
                });
            }
            const user=results[0];
            const match=await bcrypt.compare(
                password,
                user.password
            );
            if(match){
                res.json({
                    success: true,
                    username: user.username,
                    balance: user.balance,
                    wins: user.wins,
                    losses: user.losses,
                    winrate: user.winrate
                });
            }else{
                res.json({
                    success:false
                });
            }
        }
    );
});

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log("Server running");
});