package repository;

import dbConfig.DatabaseConnection;
import model.City;
import model.Job;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class CityRepository {
    public void addCity(City city) {
        String query = "INSERT INTO cities(name) VALUES (?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setString(1, city.getName());
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public City getCityById(Integer idCity) {
        String name = "";

        String query = "SELECT * FROM cities WHERE idCity = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idCity);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                name = result.getString("name");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return (new City(idCity, name));
    }

    public City getCityByName(String name) {
        int idCity = 1;

        String query = "SELECT * FROM cities WHERE name = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setString(1, name);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idCity = result.getInt("idCity");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        if (idCity != 0) {
            return (new City(idCity, name));
        }

        return null;
    }

    public List<City> getAllCities() {
        String query = "SELECT * FROM cities";
        List<City> cities = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idCity = result.getInt(1);
                City city = getCityById(idCity);
                cities.add(city);
            }

            return cities;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateCityById(Integer idCity, String field, String value) {
        if (field.equalsIgnoreCase("name")) {
            String query = "UPDATE cities SET name = ? WHERE idCity = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idCity);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteCityById(Integer idCity) {
        String query = "DELETE FROM cities WHERE idCity = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idCity);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }
}
