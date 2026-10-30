  request succeeds.
  ===========================================
  */
  const [errorMessage, setErrorMessage] = useState("");

  /*
  ===========================================
  TASK 5 — add-book form state and handlers

  TODO: hold title, author, isbn and total_copies in state,
  update only the edited field as the user types, POST them
  to `${API_URL}/books` as JSON, and clear the form once the
  const [status, setStatus] = useState("loading");
  const [books, setBooks] = useState([]);
  const [loans, setLoans] = useState([]);

const API_URL = "/api";

export default function App() {
import React,{ useEffect, useState } from "react";
import "./App.css";

const [bookForm, setBookForm] = useState({
  title: "",
  author: "",
  isbn: "",