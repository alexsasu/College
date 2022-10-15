package service;

import interfaces.ReportInterface;
import model.Job;
import repository.JobRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class JobService implements ReportInterface {
    private static JobService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final JobRepository jobRepository = new JobRepository();

    private final String fileName = "src/csvFiles/Jobs.csv";
//    private List<Job> jobs = new ArrayList<>();

    private JobService() { }

    public static JobService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new JobService();
        }

        return INSTANCE;
    }

    public Job getJobById(Integer idJob) {
        return jobRepository.getJobById(idJob);
    }

    public Job getJobByName(String name) {
        return jobRepository.getJobByName(name);
    }

    public List<Job> getAllJobs() {
        return jobRepository.getAllJobs();
    }

    public void addJob(Job job) {
        jobRepository.addJob(job);
    }

    public void updateJobById(Integer idJob, String field, String value) {
        jobRepository.updateJobById(idJob, field, value);
    }

    public void deleteJobById(Integer idJob) {
        jobRepository.deleteJobById(idJob);
    }

//    public Job getJobById(Integer idJob) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (Job job : jobs) {
//                if (job.getIdJob().equals(idJob)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return jobs.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public Job getJobByName(String name) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (Job job : jobs) {
//                if (job.getName().equals(name)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return jobs.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public List<Job> getJobs() {
//        return jobs;
//    }
//
//    public void addJob(Job job) {
//        jobs.add(job);
//    }
//
//    public void updateJobById(Integer idJob) {
//
//    }
//
//    public void deleteJobById(Integer idJob) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (Job job : jobs) {
//                if (job.getIdJob().equals(idJob)) {
//                    index = currentPosition;
//                }
//                ++currentPosition;
//            }
//            jobs.remove(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//        }
//    }

    @Override
    public void getReportInfo() {
        String[] jobs = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String job : jobs) {
                String[] jobInfo = job.split(",");
                System.out.println(String.join(" | ", jobInfo));
//                Job jobToBeAdded = new Job(Integer.parseInt(jobInfo[0]), jobInfo[1]);
//                this.jobs.add(jobToBeAdded);
            }
        } catch (ArrayIndexOutOfBoundsException | NumberFormatException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }
    }

    @Override
    public void writeToReport() {
        // Deleting file contents
        try {
            new FileOutputStream(this.fileName).close();
        } catch (IOException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }

        List<Job> jobs = getAllJobs();

        String fileHeader = "Id,Name";
        writeService.writeToFile(fileName, fileHeader);
        for (Job job : jobs) {
            String jobInfo = job.getIdJob() + "," + job.getName();

            writeService.writeToFile(fileName, jobInfo);
        }
    }
}
