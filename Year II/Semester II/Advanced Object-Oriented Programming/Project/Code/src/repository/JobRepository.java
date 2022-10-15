package repository;

import dbConfig.DatabaseConnection;
import model.Job;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class JobRepository {
    public void addJob(Job job) {
        String query = "INSERT INTO jobs(name) VALUES (?) ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setString(1, job.getName());
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public Job getJobById(Integer idJob) {
        String name = "";

        String query = "SELECT * FROM jobs WHERE idJob = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setInt(1, idJob);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                name = result.getString("name");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return (new Job(idJob, name));
    }

    public Job getJobByName(String name) {
        int idJob = 0;

        String query = "SELECT * FROM jobs WHERE name = ?";
        try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            statement.setString(1, name);
            ResultSet result = statement.executeQuery();
            while(result.next()) {
                //i have at least one record in the result set
                idJob = result.getInt("idJob");
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        if (idJob != 0) {
            return (new Job(idJob, name));
        }

        return null;
    }

    public List<Job> getAllJobs() {
        String query = "SELECT * FROM jobs";
        List<Job> jobs = new ArrayList<>();
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
            ResultSet result = statement.executeQuery();

            while(result.next()) {
                int idJob = result.getInt(1);
                Job job = getJobById(idJob);
                jobs.add(job);
            }

            return jobs;
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void updateJobById(Integer idJob, String field, String value) {
        if (field.equalsIgnoreCase("name")) {
            String query = "UPDATE jobs SET name = ? WHERE idJob = ?";
            try(PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {
                statement.setString(1, value);
                statement.setInt(2, idJob);
                statement.executeUpdate();
            } catch(SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteJobById(Integer idJob) {
        String query = "DELETE FROM jobs WHERE idJob = ? ";
        try (PreparedStatement statement = DatabaseConnection.getConnection().prepareStatement(query)) {//try with resources
            statement.setInt(1, idJob);
            statement.executeUpdate();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }
}
