});

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});

export default app;
        res.json(students);

        const students = JSON.parse(data);
        const data = fs.readFileSync(DB_PATH, "utf8");
app.get("/api/students", (req, res) => {


app.use(cors());
const DB_PATH = path.join(__dirname, "db.json");
const __dirname = path.dirname(__filename);