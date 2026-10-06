    // URL: jdbc:h2:./employeedb   Username: sa   Password: (empty)
    private static final String URL = "dbc:h2:./employeedb";
    private static final String USER = "sa";
    private static final String PASSWORD = "";

    private DBConnection() { }

    public static Connection getConnection() throws SQLException {
        // TODO: Return a connection using DriverManager.getConnection(URL, USER, PASSWORD)
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}