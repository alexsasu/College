package service;

import interfaces.ReportInterface;
import model.Service;
import repository.ServiceRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class ServiceService implements ReportInterface {
    private static ServiceService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final ServiceRepository serviceRepository = new ServiceRepository();

    private final String fileName = "src/csvFiles/Services.csv";
//    private List<Service> services = new ArrayList<>();

    private ServiceService() { }

    public static ServiceService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new ServiceService();
        }

        return INSTANCE;
    }

    public Service getServiceById(Integer idService) {
        return serviceRepository.getServiceById(idService);
    }

    public List<Service> getAllServices() {
        return serviceRepository.getAllServices();
    }

    public void addService(Service service) {
        serviceRepository.addService(service);
    }

    public void updateServiceById(Integer idService, String field, String value) {
        serviceRepository.updateServiceById(idService, field, value);
    }

    public void deleteServiceById(Integer idService) {
        serviceRepository.deleteServiceById(idService);
    }

    public List<Service> filterServicesBySellerUsername(String username) {
        return serviceRepository.filterServicesBySellerUsername(username);
    }

    public List<Service> filterServicesByJobName(String name) {
        return serviceRepository.filterServicesByJobName(name);
    }

    public List<Service> filterServicesByPriceRange(Double rangeLeft, Double rangeRight) {
        return serviceRepository.filterServicesByPriceRange(rangeLeft, rangeRight);
    }

//    public Service getServiceById(Integer idService) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (Service service : services) {
//                if (service.getIdService().equals(idService)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return services.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public List<Service> getServices() {
//        return services;
//    }
//
//    public void addService(Service service) {
//        services.add(service);
//    }
//
//    public void updateServiceById(Integer idService) {
//
//    }
//
//    public void deleteServiceById(Integer idService) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (Service service : services) {
//                if (service.getIdService().equals(idService)) {
//                    index = currentPosition;
//                }
//                ++currentPosition;
//            }
//            services.remove(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//        }
//    }

    @Override
    public void getReportInfo() {
        String[] services = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String service : services) {
                String[] serviceInfo = service.split(",");
                System.out.println(String.join(" | ", serviceInfo));
//                Service serviceToBeAdded = new Service(Integer.parseInt(serviceInfo[0]), null, serviceInfo[1], serviceInfo[2]);
//                this.services.add(serviceToBeAdded);
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

        List<Service> services = getAllServices();

        String fileHeader = "Id,Seller Id,Job Id,Description,Price,Work Schedule";
        writeService.writeToFile(fileName, fileHeader);
        for (Service service : services) {
            String serviceInfo = service.getIdService() + "," + service.getIdSeller() + "," + service.getIdJob() + "," + service.getDescription() + "," + service.getPrice() + "," + service.getWorkSchedule();

            writeService.writeToFile(fileName, serviceInfo);
        }
    }
}
