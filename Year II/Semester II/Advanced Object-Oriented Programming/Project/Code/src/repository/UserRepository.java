package repository;

import dbConfig.DatabaseConnection;
import model.Buyer;
import model.Seller;
import model.User;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Types;
import java.util.ArrayList;
import java.util.List;

public class UserRepository {
    public void addUser(User user) {
        String query = "INSERT INTO users(type, firstName, lastName, username, email, password, description, phoneNumber) VALUES (?, ?, ?, ?, ?, ?, ?, ?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setString(1, user.getType());
            statement.setString(2, user.getFirstName());
            statement.setString(3, user.getLastName());
            statement.setString(4, user.getUsername());
            statement.setString(5, user.getEmail());
            statement.setString(6, user.getPassword());
            if (user.getType().equalsIgnoreCase("seller")) {
                statement.setString(7, ((Seller) user).getDescription());
                statement.setString(8, ((Seller) user).getPhoneNumber());
            } else {
                statement.setNull(7, Types.VARCHAR);
                statement.setNull(8, Types.VARCHAR);
            }
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public User getUserById(Integer idUser) {
        String type = "";
        String firstName = "";
        String lastName = "";
        String username = "";
        String email = "";
        String password = "";
        String description = "";
        String phoneNumber = "";

        String query = "SELECT * FROM users WHERE idUser = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idUser);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                type = result.getString("type");
                firstName = result.getString("firstName");
                lastName = result.getString("lastName");
                username = result.getString("username");
                email = result.getString("email");
                password = result.getString("password");
                if (type.equalsIgnoreCase("seller")) {
                    description = result.getString("description");
                    phoneNumber = result.getString("phoneNumber");
                }
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        if (type.equalsIgnoreCase("seller")) {
            return (new Seller(idUser, type, firstName, lastName, username, email, password, description, phoneNumber));
        }
        else if (type.equalsIgnoreCase("buyer")) {
            return (new Buyer(idUser, type, firstName, lastName, username, email, password));
        }

        return null;
    }

    public User getUserByUsername(String username) {
        int idUser = 1;
        String type = "";
        String firstName = "";
        String lastName = "";
        String email = "";
        String password = "";
        String description = "";
        String phoneNumber = "";

        String query = "SELECT * FROM users WHERE username = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setString(1, username);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idUser = result.getInt("idUser");
                type = result.getString("type");
                firstName = result.getString("firstName");
                lastName = result.getString("lastName");
                email = result.getString("email");
                password = result.getString("password");
                if (type.equalsIgnoreCase("seller")) {
                    description = result.getString("description");
                    phoneNumber = result.getString("phoneNumber");
                }
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        if (type.equalsIgnoreCase("seller")) {
            return (new Seller(idUser, type, firstName, lastName, username, email, password, description, phoneNumber));
        }
        else if (type.equalsIgnoreCase("buyer")) {
            return (new Buyer(idUser, type, firstName, lastName, username, email, password));
        }

        return null;
    }

    public List<User> getAllUsers() {
        String query = "SELECT * FROM users";
        List<User> users = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idUser = result.getInt(1);
                User user = getUserById(idUser);
                users.add(user);
            }

            return users;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateUserById(Integer idUser, String field, String value) {
        if (field.equalsIgnoreCase("type")) {
            String query = "UPDATE users SET type = ?, description = ?, phoneNumber = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setNull(2, Types.VARCHAR);
                statement.setNull(3, Types.VARCHAR);
                statement.setInt(4, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("firstName")) {
            String query = "UPDATE users SET firstName = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("lastName")) {
            String query = "UPDATE users SET lastName = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("username")) {
            String query = "UPDATE users SET username = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("email")) {
            String query = "UPDATE users SET email = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }else if (field.equalsIgnoreCase("password")) {
            String query = "UPDATE users SET password = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("description") && getUserById(idUser).getType().equalsIgnoreCase("seller")) {
            String query = "UPDATE users SET description = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("phoneNumber") && getUserById(idUser).getType().equalsIgnoreCase("seller")) {
            String query = "UPDATE users SET phoneNumber = ? WHERE idUser = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idUser);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteUserById(Integer idUser) {
        String query = "DELETE FROM users WHERE idUser = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idUser);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }
}
