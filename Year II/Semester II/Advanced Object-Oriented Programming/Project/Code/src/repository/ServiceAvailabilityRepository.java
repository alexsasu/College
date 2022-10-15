package repository;

import dbConfig.DatabaseConnection;
import model.BuyerUtility;
import model.ServiceAvailability;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ServiceAvailabilityRepository {
    public void addServiceAvailability(ServiceAvailability serviceAvailability) {
        String query = "INSERT INTO services_availabilities(idService, idCity) VALUES (?, ?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, serviceAvailability.getIdService());
            statement.setInt(2, serviceAvailability.getIdCity());
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public List<ServiceAvailability> getServiceAvailabilitiesByServiceId(Integer idService) {
        int idCity = 1;

        String query = "SELECT * FROM services_availabilities WHERE idService = ?";
        List<ServiceAvailability> serviceAvailabilities = new ArrayList<>();
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idService);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idCity = result.getInt("idCity");

                serviceAvailabilities.add(new ServiceAvailability(idService, idCity));
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return serviceAvailabilities;
    }

    public ServiceAvailability getServiceAvailabilityByCityId(Integer idCity) {
        int idService = 1;

        String query = "SELECT * FROM services_availabilities WHERE idCity = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idCity);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idService = result.getInt("idService");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return (new ServiceAvailability(idService, idCity));
    }

    public List<ServiceAvailability> getAllServicesAvailabilities() {
        String query = "SELECT DISTINCT idService FROM services_availabilities";
        List<ServiceAvailability> servicesAvailabilities = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idService = result.getInt(1);
                List<ServiceAvailability> serviceAvailabilities = getServiceAvailabilitiesByServiceId(idService);
                servicesAvailabilities.addAll(serviceAvailabilities);
            }

            return servicesAvailabilities;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateServiceAvailabilityByServiceIdAndCityId(Integer idService, Integer idCity, String field, Integer value) {
        if (field.equalsIgnoreCase("idService")) {
            String query = "UPDATE services_availabilities SET idService = ? WHERE idService = ? AND idCity = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, value);
                statement.setInt(2, idService);
                statement.setInt(3, idCity);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("idCity")) {
            String query = "UPDATE services_availabilities SET idCity = ? WHERE idService = ? AND idCity = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, value);
                statement.setInt(2, idService);
                statement.setInt(3, idCity);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void updateServiceAvailabilityByCityId(Integer idCity, String field, Integer value) {
        if (field.equalsIgnoreCase("idService")) {
            String query = "UPDATE services_availabilities SET idService = ? WHERE idCity = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, value);
                statement.setInt(2, idCity);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("idCity")) {
            String query = "UPDATE services_availabilities SET idCity = ? WHERE idCity = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, value);
                statement.setInt(2, idCity);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteServiceAvailabilityByServiceIdAndCityId(Integer idService, Integer idCity) {
        String query = "DELETE FROM services_availabilities WHERE idService = ? AND idCity = ?";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idService);
            statement.setInt(2, idCity);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteServiceAvailabilityByCityId(Integer idCity) {
        String query = "DELETE FROM services_availabilities WHERE idCity = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idCity);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }
}
