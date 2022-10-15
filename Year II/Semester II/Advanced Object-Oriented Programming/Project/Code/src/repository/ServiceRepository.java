package repository;

import dbConfig.DatabaseConnection;
import model.Service;
import service.JobService;
import service.UserService;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ServiceRepository {
    UserService userService = UserService.getInstance();
    JobService jobService = JobService.getInstance();

    public void addService(Service service) {
        String query = "INSERT INTO services(idSeller, idJob, description, price, workSchedule) VALUES (?, ?, ?, ?, ?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, service.getIdSeller());
            statement.setInt(2, service.getIdJob());
            statement.setString(3, service.getDescription());
            statement.setDouble(4, service.getPrice());
            statement.setString(5, service.getWorkSchedule());
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public Service getServiceById(Integer idService) {
        int idSeller = 1;
        int idJob = 1;
        String description = "";
        double price = 0.0;
        String workSchedule = "";

        String query = "SELECT * FROM services WHERE idService = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idService);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idSeller = result.getInt("idSeller");
                idJob = result.getInt("idJob");
                description = result.getString("description");
                price = result.getDouble("price");
                workSchedule = result.getString("workSchedule");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return (new Service(idService, idSeller, idJob, description, price, workSchedule));
    }

    public List<Service> getAllServices() {
        String query = "SELECT * FROM services";
        List<Service> services = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idService = result.getInt(1);
                Service service = getServiceById(idService);
                services.add(service);
            }

            return services;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateServiceById(Integer idService, String field, String value) {
        if (field.equalsIgnoreCase("idSeller")) {
            String query = "UPDATE services SET idSeller = ? WHERE idService = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, Integer.parseInt(value));
                statement.setInt(2, idService);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("idJob")) {
            String query = "UPDATE services SET idJob = ? WHERE idService = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, Integer.parseInt(value));
                statement.setInt(2, idService);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("description")) {
            String query = "UPDATE services SET description = ? WHERE idService = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idService);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("price")) {
            String query = "UPDATE services SET price = ? WHERE idService = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setDouble(1, Double.parseDouble(value));
                statement.setInt(2, idService);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("workSchedule")) {
            String query = "UPDATE services SET workSchedule = ? WHERE idService = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idService);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteServiceById(Integer idService) {
        String query = "DELETE FROM services WHERE idService = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idService);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Service> filterServicesBySellerUsername(String username) {
        String query = "SELECT * " +
                       "FROM (services JOIN users ON (services.idSeller = users.idUser))" +
                       "WHERE username = ?";
        List<Service> services = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setString(1, username);
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idService = result.getInt(1);
                Service service = getServiceById(idService);
                if (userService.getUserById(service.getIdSeller()).getUsername().equalsIgnoreCase(username)) {
                    services.add(service);
                }
            }

            return services;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public List<Service> filterServicesByJobName(String name) {
        String query = "SELECT * " +
                       "FROM (services JOIN jobs ON (services.idJob = jobs.idJob))" +
                       "WHERE name = ?";
        List<Service> services = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setString(1, name);
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idService = result.getInt(1);
                Service service = getServiceById(idService);
                if (jobService.getJobById(service.getIdJob()).getName().equalsIgnoreCase(name)) {
                    services.add(service);
                }
            }

            return services;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public List<Service> filterServicesByPriceRange(Double rangeLeft, Double rangeRight) {
        String query = "SELECT * FROM services WHERE price >= ? AND price <= ?";
        List<Service> services = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setDouble(1, rangeLeft);
            statement.setDouble(2, rangeRight);
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idService = result.getInt(1);
                Service service = getServiceById(idService);
                services.add(service);
            }

            return services;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }
}
