
    public static Connection getConnection() throws SQLException {
        // TODO: Return a connection using DriverManager.getConnection(URL, USER, PASSWORD)

        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}