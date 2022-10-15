package service;

import interfaces.ReportInterface;
import model.ServiceAvailability;
import repository.ServiceAvailabilityRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class ServiceAvailabilityService implements ReportInterface {
    private static ServiceAvailabilityService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final ServiceAvailabilityRepository serviceAvailabilityRepository = new ServiceAvailabilityRepository();

    private final String fileName = "src/csvFiles/ServicesAvailabilities.csv";

    private ServiceAvailabilityService() { }

    public static ServiceAvailabilityService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new ServiceAvailabilityService();
        }

        return INSTANCE;
    }

    public List<ServiceAvailability> getServiceAvailabilitiesByServiceId(Integer idService) {
        return serviceAvailabilityRepository.getServiceAvailabilitiesByServiceId(idService);
    }

    public ServiceAvailability getServiceAvailabilityByCityId(Integer idCity) {
        return serviceAvailabilityRepository.getServiceAvailabilityByCityId(idCity);
    }

    public List<ServiceAvailability> getAllServicesAvailabilities() {
        return serviceAvailabilityRepository.getAllServicesAvailabilities();
    }

    public void addServiceAvailability(ServiceAvailability serviceAvailability) {
        serviceAvailabilityRepository.addServiceAvailability(serviceAvailability);
    }

    public void updateServiceAvailabilityByServiceIdAndCityId(Integer idService, Integer idCity, String field, Integer value) {
        serviceAvailabilityRepository.updateServiceAvailabilityByServiceIdAndCityId(idService, idCity, field, value);
    }

    public void updateServiceAvailabilityByCityId(Integer idCity, String field, Integer value) {
        serviceAvailabilityRepository.updateServiceAvailabilityByCityId(idCity, field, value);
    }

    public void deleteServiceAvailabilityByServiceIdAndCityId(Integer idService, Integer idCity) {
        serviceAvailabilityRepository.deleteServiceAvailabilityByServiceIdAndCityId(idService, idCity);
    }

    public void deleteServiceAvailabilityByCityId(Integer idCity) {
        serviceAvailabilityRepository.deleteServiceAvailabilityByCityId(idCity);
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
        String[] servicesAvailability = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String serviceAvailability : servicesAvailability) {
                String[] jobInfo = serviceAvailability.split(",");
                System.out.println(String.join(" | ", jobInfo));
//                ServiceAvailability serviceAvailabilityToBeAdded = new ServiceAvailability(Integer.parseInt(jobInfo[0]), Integer.parseInt(jobInfo[1]));
//                this.servicesAvailability.add(serviceAvailabilityToBeAdded);
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

        List<ServiceAvailability> servicesAvailability = getAllServicesAvailabilities();

        String fileHeader = "Service Id,City Id";
        writeService.writeToFile(fileName, fileHeader);
        for (ServiceAvailability serviceAvailability : servicesAvailability) {
            String serviceAvailabilityInfo = serviceAvailability.getIdService() + "," + serviceAvailability.getIdCity();

            writeService.writeToFile(fileName, serviceAvailabilityInfo);
        }
    }
}
