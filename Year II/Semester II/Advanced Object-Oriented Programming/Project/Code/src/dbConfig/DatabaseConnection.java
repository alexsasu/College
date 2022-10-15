package dbConfig;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnection {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/oop-java-project";
    private static final String DATABASE_USER = "Alex";
    private static final String DATABASE_PASSWORD = "SMQyLRP07";
    private static Connection connection;

    private DatabaseConnection() {
    }

    public static Connection getConnection() throws SQLException {
        try {
            if(connection == null || connection.isClosed()) {
                Class.forName("com.mysql.cj.jdbc.Driver").getConstructor();
                connection = DriverManager.getConnection(DATABASE_URL, DATABASE_USER, DATABASE_PASSWORD);
            }
        } catch (SQLException | ClassNotFoundException | NoSuchMethodException exception) {
            throw new RuntimeException("Something went wrong during connection/driver invocation.");
        }

        return connection;
    }

    public static void closeConnection() {
        try {
            if(connection != null && !connection.isClosed()) {
                connection.close();
            }
        } catch (SQLException exception) {
            throw new RuntimeException("Something went wrong while closing the database connection.");
        }
    }
}
