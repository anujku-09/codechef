import express from "express";
import cors from "cors";
import { initDB } from "./db.js";
import router from "./routes.js";
 
const app = express();
 
app.use(cors());
app.use(express.json());
 
await initDB();
 
app.use("/recipes", router);
 
const server = app.listen(8080, () => {
  console.log("Server running on Port 8080");
});
 
export default server;