package service;

import interfaces.ReportInterface;
import model.City;
import repository.CityRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class CityService implements ReportInterface {
    private static CityService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final CityRepository cityRepository = new CityRepository();

    private final String fileName = "src/csvFiles/Cities.csv";
//    private List<City> cities = new ArrayList<>();

    private CityService() { }

    public static CityService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new CityService();
        }

        return INSTANCE;
    }

    public City getCityById(Integer idCity) {
        return cityRepository.getCityById(idCity);
    }

    public City getCityByName(String name) {
        return cityRepository.getCityByName(name);
    }

    public List<City> getAllCities() {
        return cityRepository.getAllCities();
    }

    public void addCity(City city) {
        cityRepository.addCity(city);
    }

    public void updateCityById(Integer idCity, String field, String value) {
        cityRepository.updateCityById(idCity, field, value);
    }

    public void deleteCityById(Integer idCity) {
        cityRepository.deleteCityById(idCity);
    }

//    public City getCityById(Integer idCity) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (City city : cities) {
//                if (city.getIdCity().equals(idCity)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return cities.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public City getCityByName(String name) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (City city : cities) {
//                if (city.getName().equals(name)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return cities.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public List<City> getCities() {
//        return cities;
//    }
//
//    public void addCity(City city) {
//        cities.add(city);
//    }
//
//    public void updateCityById(Integer idCity) {
//
//    }
//
//    public void deleteCityById(Integer idCity) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (City city : cities) {
//                if (city.getIdCity().equals(idCity)) {
//                    index = currentPosition;
//                }
//                ++currentPosition;
//            }
//            cities.remove(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//        }
//    }

    @Override
    public void getReportInfo() {
        String[] cities = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String city : cities) {
                String[] cityInfo = city.split(",");
                System.out.println(String.join(" | ", cityInfo));
//                City cityToBeAdded = new City(Integer.parseInt(cityInfo[0]), cityInfo[1]);
//                this.cities.add(cityToBeAdded);
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

        List<City> cities = getAllCities();

        String fileHeader = "Id,Name";
        writeService.writeToFile(fileName, fileHeader);
        for (City city : cities) {
            String cityInfo = city.getIdCity() + "," + city.getName();

            writeService.writeToFile(fileName, cityInfo);
        }
    }
}
