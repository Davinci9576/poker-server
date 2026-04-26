const express = require("express");
const app = express();

app.use(express.json());

let leaderboard = [];

// POST → add score
app.post("/score", (req, res) => {
    try {
        console.log("Received:", req.body); // 🔍 debug

        const { name, money } = req.body;

        if (!name || money === undefined) {
            return res.status(400).json({ error: "Invalid data" });
        }

        leaderboard.push({ name, money });

        res.json({ message: "Score added!" });

    } catch (err) {
        console.error("Error:", err);
        res.status(500).json({ error: "Server error" });
    }
});

// GET → get leaderboard
app.get("/leaderboard", (req, res) => {
    const sorted = [...leaderboard].sort((a, b) => b.money - a.money);
    res.json(sorted);
});

app.listen(3000, () => {
    console.log("Server running on port 3000");
});