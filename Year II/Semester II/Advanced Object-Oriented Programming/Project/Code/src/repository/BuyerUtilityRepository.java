package repository;

import dbConfig.DatabaseConnection;
import model.*;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class BuyerUtilityRepository {
    public void addBuyerUtilityInfo(BuyerUtility buyerUtility) {
        String query = "INSERT INTO buyers_utilities(idUtility, idService, idBuyer, type, serviceAddedDate, feedback) VALUES (?, ?, ?, ?, ?, ?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, buyerUtility.getIdUtility());
            statement.setInt(2, buyerUtility.getIdService());
            statement.setInt(3, buyerUtility.getIdBuyer());
            statement.setString(4, buyerUtility.getType());
            statement.setDate(5, buyerUtility.getServiceAddedDate());
            if (buyerUtility.getType().equalsIgnoreCase("history")) {
                statement.setString(6, ((BuyerHistory) buyerUtility).getFeedback());
            } else {
                statement.setNull(6, Types.DATE);
            }
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public List<BuyerUtility> getBuyerUtilityById(Integer idUtility) {
        int idService = 1;
        int idBuyer = 1;
        String type = "";
        Date serviceAddedDate = null;
        String feedback = "";

        String query = "SELECT * FROM buyers_utilities WHERE idUtility = ?";
        List<BuyerUtility> buyerUtilities = new ArrayList<>();
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idUtility);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idService = result.getInt("idService");
                idBuyer = result.getInt("idBuyer");
                type = result.getString("type");
                serviceAddedDate = result.getDate("serviceAddedDate");
                if (type.equalsIgnoreCase("history")) {
                    feedback = result.getString("feedback");
                }

                if (type.equalsIgnoreCase("history")) {
                    buyerUtilities.add(new BuyerHistory(idUtility, idService, idBuyer, type, serviceAddedDate, feedback));
                }
                else if (type.equalsIgnoreCase("cart")) {
                    buyerUtilities.add(new BuyerUtility(idUtility, idService, idBuyer, type, serviceAddedDate));
                }
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return buyerUtilities;
    }

    public List<BuyerUtility> getAllBuyersUtilities() {
        String query = "SELECT DISTINCT idUtility FROM buyers_utilities";
        List<BuyerUtility> buyersUtilities = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idBuyerUtility = result.getInt(1);
                List<BuyerUtility> buyerUtility = getBuyerUtilityById(idBuyerUtility);
                buyersUtilities.addAll(buyerUtility);
            }

            return buyersUtilities;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateBuyerUtilityById(Integer idBuyerUtility, String field, String value) {
        if (field.equalsIgnoreCase("idService")) {
            String query = "UPDATE buyers_utilities SET idService = ? WHERE idUtility = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, Integer.parseInt(value));
                statement.setNull(2, idBuyerUtility);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("idBuyer")) {
            String query = "UPDATE buyers_utilities SET idBuyer = ? WHERE idUtility = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setInt(1, Integer.parseInt(value));
                statement.setNull(2, idBuyerUtility);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("type")) {
            String query = "UPDATE buyers_utilities SET type = ?, feedback = ? WHERE idUtility = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setNull(2, Types.VARCHAR);
                statement.setInt(3, idBuyerUtility);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("serviceAddedDate")) {
            String query = "UPDATE buyers_utilities SET serviceAddedDate = ? WHERE idUtility = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setDate(1, Date.valueOf(value));
                statement.setInt(2, idBuyerUtility);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        } else if (field.equalsIgnoreCase("feedback") && getBuyerUtilityById(idBuyerUtility).get(0).getType().equalsIgnoreCase("history")) {
            String query = "UPDATE buyers_utilities SET feedback = ? WHERE idUtility = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idBuyerUtility);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteBuyerUtilityById(Integer idBuyerUtility) {
        String query = "DELETE FROM buyers_utilities WHERE idUtility = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idBuyerUtility);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }
}
