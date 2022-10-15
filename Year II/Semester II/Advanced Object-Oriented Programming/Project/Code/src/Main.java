import model.*;
import service.*;

import java.sql.Date;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void clrscr() {
        for (int i = 0; i < 30; ++i) {
            System.out.println();
        }
    }

    public static void pressEnterToContinue()
    {
        System.out.println("Press Enter key to continue...");
        try {
            System.in.read();
        } catch (Exception e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        UserService userService = UserService.getInstance();
        ServiceService serviceService = ServiceService.getInstance();
        BuyerUtilityService buyerUtilityService = BuyerUtilityService.getInstance();
        JobService jobService = JobService.getInstance();
        CityService cityService = CityService.getInstance();
        ServiceAvailabilityService serviceAvailabilityService = ServiceAvailabilityService.getInstance();

        Boolean continueNavigation = true;
        Scanner sc = new Scanner(System.in);

        System.out.println("\nWelcome back, administrator!\n");

        while (continueNavigation) {
            System.out.println("What do you wish to do?\n");
            System.out.println("Get data from report - 1");
            System.out.println("Export data to report - 2");
            System.out.println("Add new entry - 3");
            System.out.println("Get entry by ID and print it to screen - 4");
            System.out.println("Get entry by name and print it to screen - 5");
            System.out.println("Print all entries of certain type to screen - 6");
            System.out.println("Update entry by ID - 7");
            System.out.println("Remove entry - 8");
            System.out.println("Class specific operations - 9");
            System.out.println("EXIT MENU - 10\n");

            System.out.print("Choose option: ");
            Integer option = Integer.parseInt(sc.nextLine());
            clrscr();

            switch (option) {
                case 1: {
                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Get data from \"Users.csv\" - 1");
                        System.out.println("Get data from \"Services.csv\" - 2");
                        System.out.println("Get data from \"BuyersUtilities.csv\" - 3");
                        System.out.println("Get data from \"Jobs.csv\" - 4");
                        System.out.println("Get data from \"Cities.csv\" - 5");
                        System.out.println("Get data from \"ServicesAvailabilities.csv\" - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch(InterruptedException e) { System.out.println(e.getClass() + " " + e.getMessage()); }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        userService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                    case 2: {
                                        serviceService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                    case 3: {
                                        buyerUtilityService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                    case 4: {
                                        jobService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                    case 5: {
                                        cityService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                    case 6: {
                                        serviceAvailabilityService.getReportInfo();

                                        System.out.println();
                                        pressEnterToContinue();
                                        clrscr();

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 2: {
                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Export data to \"Users.csv\" - 1");
                        System.out.println("Export data to \"Services.csv\" - 2");
                        System.out.println("Export data to \"BuyersUtilities.csv\" - 3");
                        System.out.println("Export data to \"Jobs.csv\" - 4");
                        System.out.println("Export data to \"Cities.csv\" - 5");
                        System.out.println("Export data to \"ServicesAvailabilities.csv\" - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        userService.writeToReport();

                                        System.out.println("Successfully exported users!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 2: {
                                        serviceService.writeToReport();

                                        System.out.println("Successfully exported services!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 3: {
                                        buyerUtilityService.writeToReport();

                                        System.out.println("Successfully exported buyers utilities!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 4: {
                                        jobService.writeToReport();

                                        System.out.println("Successfully exported jobs!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 5: {
                                        cityService.writeToReport();

                                        System.out.println("Successfully exported cities!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 6: {
                                        serviceAvailabilityService.writeToReport();

                                        System.out.println("Successfully exported services availabilities!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 3: {
                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Add new user - 1");
                        System.out.println("Add new service - 2");
                        System.out.println("Add new buyer utility info - 3");
                        System.out.println("Add new job - 4");
                        System.out.println("Add new city - 5");
                        System.out.println("Add new service availability - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                Scanner scInfo = new Scanner(System.in);
                                Scanner scNumberInfo = new Scanner(System.in);

                                switch (option) {
                                    case 1: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.println("Add new seller - 1");
                                            System.out.println("Add new buyer - 2\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 2)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            }
                                            else if (option != 0) {
                                                switch (option) {
                                                    case 1: {
                                                        String type = "seller";
                                                        System.out.print("First name: ");
                                                        String firstName = scInfo.nextLine();
                                                        System.out.print("Last name: ");
                                                        String lastName = scInfo.nextLine();
                                                        System.out.print("Username: ");
                                                        String username = scInfo.nextLine();
                                                        System.out.print("E-mail: ");
                                                        String email = scInfo.nextLine();
                                                        System.out.print("Password: ");
                                                        String password = scInfo.nextLine();
                                                        System.out.print("Description: ");
                                                        String description = scInfo.nextLine();
                                                        System.out.print("Phone number: ");
                                                        String phoneNumber = scInfo.nextLine();

                                                        userService.addUser(new Seller(type, firstName, lastName, username, email, password, description, phoneNumber));

                                                        System.out.println();
                                                        System.out.println("Seller successfully added!");
                                                        try {
                                                            Thread.sleep(2000);
                                                        } catch (InterruptedException e) {
                                                            System.out.println(e.getClass() + " " + e.getMessage());
                                                        }
                                                        clrscr();

                                                        break;
                                                    }
                                                    case 2: {
                                                        String type = "buyer";
                                                        System.out.print("First name: ");
                                                        String firstName = scInfo.nextLine();
                                                        System.out.print("Last name: ");
                                                        String lastName = scInfo.nextLine();
                                                        System.out.print("Username: ");
                                                        String username = scInfo.nextLine();
                                                        System.out.print("E-mail: ");
                                                        String email = scInfo.nextLine();
                                                        System.out.print("Password: ");
                                                        String password = scInfo.nextLine();

                                                        userService.addUser(new Buyer(type, firstName, lastName, username, email, password));

                                                        System.out.println();
                                                        System.out.println("Buyer successfully added!");
                                                        try {
                                                            Thread.sleep(2000);
                                                        } catch (InterruptedException e) {
                                                            System.out.println(e.getClass() + " " + e.getMessage());
                                                        }
                                                        clrscr();

                                                        break;
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        }

                                        break;
                                    }
                                    case 2: {
                                        System.out.print("Seller Id: ");
                                        Integer idSeller = scNumberInfo.nextInt();
                                        System.out.print("Job Id: ");
                                        Integer idJob = scNumberInfo.nextInt();
                                        System.out.print("Description: ");
                                        String description = scInfo.nextLine();
                                        System.out.print("Price: ");
                                        Double price = scNumberInfo.nextDouble();
                                        System.out.print("Work schedule: ");
                                        String workSchedule = scInfo.nextLine();

                                        serviceService.addService(new Service(idSeller, idJob, description, price, workSchedule));

                                        System.out.println();
                                        System.out.println("Service successfully added!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 3: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.println("Add new buyer cart info - 1");
                                            System.out.println("Add new buyer history info - 2\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 2)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            }
                                            else if (option != 0) {
                                                switch (option) {
                                                    case 1: {
                                                        System.out.print("Utility id: ");
                                                        Integer idUtility = scNumberInfo.nextInt();
                                                        System.out.print("Service id: ");
                                                        Integer idService = scNumberInfo.nextInt();
                                                        System.out.print("Buyer id: ");
                                                        Integer idBuyer = scNumberInfo.nextInt();
                                                        String type = "cart";
                                                        java.util.Date utilDate = new java.util.Date();
                                                        java.sql.Date serviceAddedDate = new Date(utilDate.getTime());

                                                        buyerUtilityService.addBuyerUtilityInfo(new BuyerUtility(idUtility, idService, idBuyer, type, serviceAddedDate));

                                                        System.out.println();
                                                        System.out.println("Buyer cart info successfully added!");
                                                        try {
                                                            Thread.sleep(2000);
                                                        } catch (InterruptedException e) {
                                                            System.out.println(e.getClass() + " " + e.getMessage());
                                                        }
                                                        clrscr();

                                                        break;
                                                    }
                                                    case 2: {
                                                        System.out.print("Utility id: ");
                                                        Integer idUtility = scNumberInfo.nextInt();
                                                        System.out.print("Service id: ");
                                                        Integer idService = scNumberInfo.nextInt();
                                                        System.out.print("Buyer id: ");
                                                        Integer idBuyer = scNumberInfo.nextInt();
                                                        String type = "history";
                                                        java.util.Date utilDate = new java.util.Date();
                                                        java.sql.Date serviceAddedDate = new Date(utilDate.getTime());
                                                        System.out.print("Feedback: ");
                                                        String feedback = scInfo.nextLine();

                                                        buyerUtilityService.addBuyerUtilityInfo(new BuyerHistory(idUtility, idService, idBuyer, type, serviceAddedDate, feedback));

                                                        System.out.println();
                                                        System.out.println("Buyer history info successfully added!");
                                                        try {
                                                            Thread.sleep(2000);
                                                        } catch (InterruptedException e) {
                                                            System.out.println(e.getClass() + " " + e.getMessage());
                                                        }
                                                        clrscr();

                                                        break;
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        }

                                        break;
                                    }
                                    case 4: {
                                        System.out.print("Job name: ");
                                        String name = scInfo.nextLine();

                                        jobService.addJob(new Job(name));

                                        System.out.println();
                                        System.out.println("Job successfully added!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 5: {
                                        System.out.print("City name: ");
                                        String name = scInfo.nextLine();

                                        cityService.addCity(new City(name));

                                        System.out.println();
                                        System.out.println("City successfully added!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                    case 6: {
                                        System.out.print("Service id: ");
                                        Integer idService = scNumberInfo.nextInt();
                                        System.out.print("City id: ");
                                        Integer idCity = scNumberInfo.nextInt();

                                        serviceAvailabilityService.addServiceAvailability(new ServiceAvailability(idService, idCity));

                                        System.out.println();
                                        System.out.println("Service availability successfully added!");
                                        try {
                                            Thread.sleep(2000);
                                        } catch (InterruptedException e) {
                                            System.out.println(e.getClass() + " " + e.getMessage());
                                        }
                                        clrscr();

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 4: {
                    Scanner scId = new Scanner(System.in);
                    Integer id;

                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Print user by id to screen - 1");
                        System.out.println("Print service by id to screen - 2");
                        System.out.println("Print buyer utility by id to screen - 3");
                        System.out.println("Print job by id to screen - 4");
                        System.out.println("Print city by id to screen - 5");
                        System.out.println("Print service availability by service id to screen - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        List<User> users = userService.getAllUsers();

                                        if (!users.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which user do you wish to print?\n");

                                                List<Integer> userIds = users.stream().
                                                        map(User::getIdUser).toList();
                                                List<String> userIdsToStrings = userIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUserIds = userIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated users):");
                                                System.out.println(stringOfAllUserIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!userIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(userService.getUserById(id) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no users to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 2: {
                                        List<Service> services = serviceService.getAllServices();

                                        if (!services.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service do you wish to print?\n");

                                                List<Integer> serviceIds = services.stream().
                                                        map(Service::getIdService).toList();
                                                List<String> serviceIdsToStrings = serviceIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllServiceIds = serviceIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated services):");
                                                System.out.println(stringOfAllServiceIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!serviceIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(serviceService.getServiceById(id) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no services to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 3: {
                                        List<BuyerUtility> buyersUtilities = buyerUtilityService.getAllBuyersUtilities();

                                        if (!buyersUtilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which buyer utility do you wish to print?\n");

                                                List<Integer> utilityIds = buyersUtilities.stream().
                                                        map(BuyerUtility::getIdUtility).distinct().toList();
                                                List<String> utilityIdsToStrings = utilityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUtilityIds = utilityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated buyer utilities):");
                                                System.out.println(stringOfAllUtilityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!utilityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            List<BuyerUtility> buyerUtility = buyerUtilityService.getBuyerUtilityById(id);
                                            buyerUtility.forEach( (buyerUtilityInfo) -> { System.out.println(buyerUtilityInfo); } );
                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no buyer utilities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 4: {
                                        List<Job> jobs = jobService.getAllJobs();

                                        if (!jobs.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which job do you wish to print?\n");

                                                List<Integer> jobIds = jobs.stream().
                                                        map(Job::getIdJob).toList();
                                                List<String> jobIdsToStrings = jobIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllJobIds = jobIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated jobs):");
                                                System.out.println(stringOfAllJobIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!jobIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(jobService.getJobById(id) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no jobs to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 5: {
                                        List<City> cities = cityService.getAllCities();

                                        if (!cities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which city do you wish to print?\n");

                                                List<Integer> cityIds = cities.stream().
                                                        map(City::getIdCity).toList();
                                                List<String> cityIdsToStrings = cityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllCityIds = cityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated cities):");
                                                System.out.println(stringOfAllCityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!cityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(cityService.getCityById(id) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no cities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 6: {
                                        List<ServiceAvailability> servicesAvailabilities = serviceAvailabilityService.getAllServicesAvailabilities();

                                        if (!servicesAvailabilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service's availabilities do you wish to print?\n");

                                                List<Integer> serviceAvailabilitiesServiceIds = servicesAvailabilities.stream().
                                                        map(ServiceAvailability::getIdService).distinct().toList();
                                                List<String> serviceAvailabilitiesServiceIdsToStrings = serviceAvailabilitiesServiceIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllServiceAvailabilityServiceIds = serviceAvailabilitiesServiceIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (service ids indicating their associated service availabilities):");
                                                System.out.println(stringOfAllServiceAvailabilityServiceIds + "\n");

                                                System.out.print("Insert service id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!serviceAvailabilitiesServiceIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            List<ServiceAvailability> serviceAvailabilities = serviceAvailabilityService.getServiceAvailabilitiesByServiceId(id);
                                            serviceAvailabilities.forEach( (serviceAvailability) -> { System.out.println(serviceAvailability); } );
                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no service availabilities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 5: {
                    Scanner scName = new Scanner(System.in);
                    String name;

                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Print user by username to screen - 1");
                        System.out.println("Print job by name to screen - 2");
                        System.out.println("Print city by name to screen - 3\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 3)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        List<User> users = userService.getAllUsers();

                                        if (!users.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which user do you wish to print?\n");

                                                List<String> userUsernames = users.stream().
                                                        map(User::getUsername).toList();
                                                String stringOfAllUserUsernames = userUsernames.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following usernames (usernames indicating their associated users):");
                                                System.out.println(stringOfAllUserUsernames + "\n");

                                                System.out.print("Insert username: ");
                                                name = scName.nextLine();

                                                System.out.println();

                                                if (!userUsernames.contains(name)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(userService.getUserByUsername(name) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no users to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 2: {
                                        List<Job> jobs = jobService.getAllJobs();

                                        if (!jobs.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which job do you wish to print?\n");

                                                List<String> jobNames = jobs.stream().
                                                        map(Job::getName).toList();
                                                String stringOfAllJobNames = jobNames.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following job names (job names indicating their associated jobs):");
                                                System.out.println(stringOfAllJobNames + "\n");

                                                System.out.print("Insert job name: ");
                                                name = scName.nextLine();

                                                System.out.println();

                                                if (!jobNames.contains(name)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(jobService.getJobByName(name) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no jobs to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 3: {
                                        List<City> cities = cityService.getAllCities();

                                        if (!cities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which city do you wish to print?\n");

                                                List<String> cityNames = cities.stream().
                                                        map(City::getName).toList();
                                                String stringOfAllCityNames = cityNames.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following city names (city names indicating their associated cities):");
                                                System.out.println(stringOfAllCityNames + "\n");

                                                System.out.print("Insert city name: ");
                                                name = scName.nextLine();

                                                System.out.println();

                                                if (!cityNames.contains(name)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            System.out.println(cityService.getCityByName(name) + "\n");
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no cities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 6: {
                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Print all users to screen - 1");
                        System.out.println("Print all services to screen - 2");
                        System.out.println("Print all buyer utilities to screen - 3");
                        System.out.println("Print all jobs to screen - 4");
                        System.out.println("Print all cities to screen - 5");
                        System.out.println("Print all service availabilities to screen - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        List<User> users = userService.getAllUsers();

                                        if (!users.isEmpty()) {
                                            System.out.println("All of the stored users:\n");

                                            users.forEach( (user) -> { System.out.println(user); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no users to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 2: {
                                        List<Service> services = serviceService.getAllServices();

                                        if (!services.isEmpty()) {
                                            System.out.println("All of the stored services:\n");

                                            services.forEach( (service) -> { System.out.println(service); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no services to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 3: {
                                        List<BuyerUtility> buyersUtilities = buyerUtilityService.getAllBuyersUtilities();

                                        if (!buyersUtilities.isEmpty()) {
                                            System.out.println("All of the stored buyer utilities:\n");

                                            buyersUtilities.forEach( (buyerUtilityInfo) -> { System.out.println(buyerUtilityInfo); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no buyer utilities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 4: {
                                        List<Job> jobs = jobService.getAllJobs();

                                        if (!jobs.isEmpty()) {
                                            System.out.println("All of the stored jobs:\n");

                                            jobs.forEach( (job) -> { System.out.println(job); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no jobs to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 5: {
                                        List<City> cities = cityService.getAllCities();

                                        if (!cities.isEmpty()) {
                                            System.out.println("All of the stored cities:\n");

                                            cities.forEach( (city) -> { System.out.println(city); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no cities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 6: {
                                        List<ServiceAvailability> servicesAvailabilities = serviceAvailabilityService.getAllServicesAvailabilities();

                                        if (!servicesAvailabilities.isEmpty()) {
                                            System.out.println("All of the stored service availabilities:\n");

                                            servicesAvailabilities.forEach( (serviceAvailability) -> { System.out.println(serviceAvailability); } );

                                            System.out.println();
                                            pressEnterToContinue();

                                            clrscr();
                                        } else {
                                            System.out.println("There are no service availabilities to print!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 7: {
                    Scanner scId = new Scanner(System.in);
                    Integer id;
                    Integer id2;
                    Scanner scFieldName = new Scanner(System.in);
                    String fieldName;
                    Scanner scFieldValue = new Scanner(System.in);
                    String fieldValue;

                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Update user - 1");
                        System.out.println("Update service - 2");
                        System.out.println("Update buyer utility - 3");
                        System.out.println("Update job - 4");
                        System.out.println("Update city - 5");
                        System.out.println("Update service availability - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        List<User> users = userService.getAllUsers();

                                        if (!users.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which user do you wish to update?\n");

                                                List<Integer> userIds = users.stream().
                                                        map(User::getIdUser).toList();
                                                List<String> userIdsToStrings = userIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUserIds = userIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated users):");
                                                System.out.println(stringOfAllUserIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!userIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableUserFields = new ArrayList<String>();
                                            updatableUserFields.add("type");
                                            updatableUserFields.add("firstName");
                                            updatableUserFields.add("lastName");
                                            updatableUserFields.add("username");
                                            updatableUserFields.add("email");
                                            updatableUserFields.add("password");
                                            if (userService.getUserById(id).getType().equalsIgnoreCase("seller")) {
                                                updatableUserFields.add("description");
                                                updatableUserFields.add("phoneNumber");
                                            }

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllUserFields = String.join(", ", updatableUserFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllUserFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableUserFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            userService.updateUserById(id, fieldName, fieldValue);
                                            System.out.println();

                                            System.out.println("User successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no users to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 2: {
                                        List<Service> services = serviceService.getAllServices();

                                        if (!services.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service do you wish to update?\n");

                                                List<Integer> serviceIds = services.stream().
                                                        map(Service::getIdService).toList();
                                                List<String> serviceIdsToStrings = serviceIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllServiceIds = serviceIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated services):");
                                                System.out.println(stringOfAllServiceIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!serviceIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableServiceFields = new ArrayList<String>();
                                            updatableServiceFields.add("idSeller");
                                            updatableServiceFields.add("idJob");
                                            updatableServiceFields.add("description");
                                            updatableServiceFields.add("price");
                                            updatableServiceFields.add("workSchedule");

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllServiceFields = String.join(", ", updatableServiceFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllServiceFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableServiceFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            serviceService.updateServiceById(id, fieldName, fieldValue);
                                            System.out.println();

                                            System.out.println("Service successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no services to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 3: {
                                        List<BuyerUtility> buyersUtilities = buyerUtilityService.getAllBuyersUtilities();

                                        if (!buyersUtilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which buyer utility do you wish to update?\n");

                                                List<Integer> utilityIds = buyersUtilities.stream().
                                                        map(BuyerUtility::getIdUtility).distinct().toList();
                                                List<String> utilityIdsToStrings = utilityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUtilityIds = utilityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated buyer utilities):");
                                                System.out.println(stringOfAllUtilityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!utilityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableBuyerUtilityFields = new ArrayList<String>();
                                            updatableBuyerUtilityFields.add("idService");
                                            updatableBuyerUtilityFields.add("idBuyer");
                                            updatableBuyerUtilityFields.add("type");
                                            updatableBuyerUtilityFields.add("serviceAddedDate");
                                            if (buyerUtilityService.getBuyerUtilityById(id).get(0).getType().equalsIgnoreCase("history")) {
                                                updatableBuyerUtilityFields.add("feedback");
                                            }

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllBuyerUtilityFields = String.join(", ", updatableBuyerUtilityFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllBuyerUtilityFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableBuyerUtilityFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            buyerUtilityService.updateBuyerUtilityById(id, fieldName, fieldValue);
                                            System.out.println();

                                            System.out.println("Buyer utility successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no buyer utilities to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 4: {
                                        List<Job> jobs = jobService.getAllJobs();

                                        if (!jobs.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which job do you wish to update?\n");

                                                List<Integer> jobIds = jobs.stream().
                                                        map(Job::getIdJob).toList();
                                                List<String> jobIdsToStrings = jobIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllJobIds = jobIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated jobs):");
                                                System.out.println(stringOfAllJobIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!jobIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableJobFields = new ArrayList<String>();
                                            updatableJobFields.add("name");

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllJobFields = String.join(", ", updatableJobFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllJobFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableJobFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            jobService.updateJobById(id, fieldName, fieldValue);
                                            System.out.println();

                                            System.out.println("Job successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no jobs to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 5: {
                                        List<City> cities = cityService.getAllCities();

                                        if (!cities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which city do you wish to update?\n");

                                                List<Integer> cityIds = cities.stream().
                                                        map(City::getIdCity).toList();
                                                List<String> cityIdsToStrings = cityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllCityIds = cityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated cities):");
                                                System.out.println(stringOfAllCityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!cityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableCityFields = new ArrayList<String>();
                                            updatableCityFields.add("name");

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllCityFields = String.join(", ", updatableCityFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllCityFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableCityFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            cityService.updateCityById(id, fieldName, fieldValue);
                                            System.out.println();

                                            System.out.println("City successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no cities to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 6: {
                                        List<ServiceAvailability> servicesAvailabilities = serviceAvailabilityService.getAllServicesAvailabilities();

                                        if (!servicesAvailabilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service availability do you wish to update?\n");

                                                List<Integer> servicesAvailabilitiesServiceIds = servicesAvailabilities.stream().
                                                        map(ServiceAvailability::getIdService).toList();
                                                List<Integer> servicesAvailabilitiesCityIds = servicesAvailabilities.stream().
                                                        map(ServiceAvailability::getIdCity).toList();
                                                String servicesAvailabilitiesToString = "";
                                                for (int i = 0; i < servicesAvailabilitiesCityIds.size(); ++i) {
                                                    servicesAvailabilitiesToString += "(" + servicesAvailabilitiesServiceIds.get(i) + ", " + servicesAvailabilitiesCityIds.get(i) + ") ";
                                                }

                                                System.out.println("Insert one of the following tuple of numbers (service ids and city ids indicating their associated service availabilities):");
                                                System.out.println(servicesAvailabilitiesToString + "\n");

                                                System.out.print("Insert service id: ");
                                                id = Integer.parseInt(scId.nextLine());
                                                System.out.print("Insert city id: ");
                                                id2 = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!servicesAvailabilitiesServiceIds.contains(id) || !servicesAvailabilitiesCityIds.contains(id2)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            List<String> updatableServiceAvailabilityFields = new ArrayList<String>();
                                            updatableServiceAvailabilityFields.add("idService");
                                            updatableServiceAvailabilityFields.add("idCity");

                                            while (true) {
                                                System.out.println("Which field do you wish to update?\n");

                                                String stringOfAllServiceAvailabilityFields = String.join(", ", updatableServiceAvailabilityFields);

                                                System.out.println("Insert one of the following field names:");
                                                System.out.println(stringOfAllServiceAvailabilityFields + "\n");

                                                System.out.print("Insert field name: ");
                                                fieldName = scFieldName.nextLine();

                                                System.out.println();

                                                if (!updatableServiceAvailabilityFields.contains(fieldName)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    clrscr();
                                                    break;
                                                }
                                            }

                                            System.out.print("Insert value for \"" + fieldName + "\" field: ");
                                            fieldValue = scFieldValue.nextLine();

                                            serviceAvailabilityService.updateServiceAvailabilityByServiceIdAndCityId(id, id2, fieldName, Integer.parseInt(fieldValue));
                                            System.out.println();

                                            System.out.println("Service availability successfully updated!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no service availabilities to update!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 8: {
                    Scanner scId = new Scanner(System.in);
                    Integer id;
                    Integer id2;

                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("Remove user - 1");
                        System.out.println("Remove service - 2");
                        System.out.println("Remove buyer utility - 3");
                        System.out.println("Remove job - 4");
                        System.out.println("Remove city - 5");
                        System.out.println("Remove service availability - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        List<User> users = userService.getAllUsers();

                                        if (!users.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which user do you wish to remove?\n");

                                                List<Integer> userIds = users.stream().
                                                        map(User::getIdUser).toList();
                                                List<String> userIdsToStrings = userIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUserIds = userIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated users):");
                                                System.out.println(stringOfAllUserIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!userIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            userService.deleteUserById(id);

                                            System.out.println("User successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no users to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 2: {
                                        List<Service> services = serviceService.getAllServices();

                                        if (!services.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service do you wish to remove?\n");

                                                List<Integer> serviceIds = services.stream().
                                                        map(Service::getIdService).toList();
                                                List<String> serviceIdsToStrings = serviceIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllServiceIds = serviceIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated services):");
                                                System.out.println(stringOfAllServiceIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!serviceIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            serviceService.deleteServiceById(id);

                                            System.out.println("Service successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no services to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 3: {
                                        List<BuyerUtility> buyersUtilities = buyerUtilityService.getAllBuyersUtilities();

                                        if (!buyersUtilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which buyer utility do you wish to remove?\n");

                                                List<Integer> utilityIds = buyersUtilities.stream().
                                                        map(BuyerUtility::getIdUtility).distinct().toList();
                                                List<String> utilityIdsToStrings = utilityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllUtilityIds = utilityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated buyer utilities):");
                                                System.out.println(stringOfAllUtilityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!utilityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            buyerUtilityService.deleteBuyerUtilityById(id);

                                            System.out.println("Buyer utility successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no buyer utilities to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 4: {
                                        List<Job> jobs = jobService.getAllJobs();

                                        if (!jobs.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which job do you wish to remove?\n");

                                                List<Integer> jobIds = jobs.stream().
                                                        map(Job::getIdJob).toList();
                                                List<String> jobIdsToStrings = jobIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllJobIds = jobIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated jobs):");
                                                System.out.println(stringOfAllJobIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!jobIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            jobService.deleteJobById(id);

                                            System.out.println("Job successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no jobs to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 5: {
                                        List<City> cities = cityService.getAllCities();

                                        if (!cities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which city do you wish to remove?\n");

                                                List<Integer> cityIds = cities.stream().
                                                        map(City::getIdCity).toList();
                                                List<String> cityIdsToStrings = cityIds.stream().
                                                        map(String::valueOf).toList();
                                                String stringOfAllCityIds = cityIdsToStrings.stream().
                                                        map(String::valueOf).
                                                        collect(Collectors.joining(", "));

                                                System.out.println("Insert one of the following numbers (ids indicating their associated cities):");
                                                System.out.println(stringOfAllCityIds + "\n");

                                                System.out.print("Insert id: ");
                                                id = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!cityIds.contains(id)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            cityService.deleteCityById(id);

                                            System.out.println("City successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no cities to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                    case 6: {
                                        List<ServiceAvailability> servicesAvailabilities = serviceAvailabilityService.getAllServicesAvailabilities();

                                        if (!servicesAvailabilities.isEmpty()) {
                                            while (true) {
                                                System.out.println("Which service availability do you wish to remove?\n");

                                                List<Integer> servicesAvailabilitiesServiceIds = servicesAvailabilities.stream().
                                                        map(ServiceAvailability::getIdService).toList();
                                                List<Integer> servicesAvailabilitiesCityIds = servicesAvailabilities.stream().
                                                        map(ServiceAvailability::getIdCity).toList();
                                                String servicesAvailabilitiesToString = "";
                                                for (int i = 0; i < servicesAvailabilitiesCityIds.size(); ++i) {
                                                    servicesAvailabilitiesToString += "(" + servicesAvailabilitiesServiceIds.get(i) + ", " + servicesAvailabilitiesCityIds.get(i) + ") ";
                                                }

                                                System.out.println("Insert one of the following numbers (service ids indicating their associated service availabilities):");
                                                System.out.println(servicesAvailabilitiesToString + "\n");

                                                System.out.print("Insert service id: ");
                                                id = Integer.parseInt(scId.nextLine());
                                                System.out.print("Insert city id: ");
                                                id2 = Integer.parseInt(scId.nextLine());

                                                System.out.println();

                                                if (!servicesAvailabilitiesServiceIds.contains(id) || !servicesAvailabilitiesCityIds.contains(id2)) {
                                                    System.out.println("Wrong input!");
                                                    try {
                                                        Thread.sleep(2000);
                                                    } catch (InterruptedException e) {
                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                    }
                                                    clrscr();
                                                } else {
                                                    break;
                                                }
                                            }

                                            serviceAvailabilityService.deleteServiceAvailabilityByServiceIdAndCityId(id, id2);

                                            System.out.println("Service availability successfully removed!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        } else {
                                            System.out.println("There are no service availabilities to remove!");
                                            try {
                                                Thread.sleep(2000);
                                            } catch (InterruptedException e) {
                                                System.out.println(e.getClass() + " " + e.getMessage());
                                            }
                                            clrscr();
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 9: {
                    while (true) {
                        System.out.println("Go back - 0\n");

                        System.out.println("User specific operations - 1");
                        System.out.println("Service specific operations - 2");
                        System.out.println("Buyer utility specific operations - 3");
                        System.out.println("Job specific operations - 4");
                        System.out.println("City specific operations - 5");
                        System.out.println("Service availability specific operations - 6\n");

                        System.out.print("Choose option: ");
                        option = Integer.parseInt(sc.nextLine());
                        clrscr();

                        if ((option < 0) || (option > 6)) {
                            System.out.println("Wrong input!");
                            try {
                                Thread.sleep(2000);
                            } catch (InterruptedException e) {
                                System.out.println(e.getClass() + " " + e.getMessage());
                            }
                            clrscr();
                        } else {
                            if (option != 0) {
                                switch (option) {
                                    case 1: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.println("Print all users sorted by username - 1\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 1)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {
                                                    switch (option) {
                                                        case 1: {
                                                            List<User> users = userService.getUsersSortedByUsername();

                                                            if (!users.isEmpty()) {
                                                                System.out.println("All of the stored users, sorted by username:\n");

                                                                users.forEach( (user) -> { System.out.println(user); } );

                                                                System.out.println();
                                                                pressEnterToContinue();

                                                                try {
                                                                    Thread.sleep(2000);
                                                                } catch (InterruptedException e) {
                                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                                }
                                                                clrscr();
                                                            } else {
                                                                System.out.println("There are no users to print!");
                                                                try {
                                                                    Thread.sleep(2000);
                                                                } catch (InterruptedException e) {
                                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                                }
                                                                clrscr();
                                                            }

                                                            break;
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                    case 2: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.println("Filter services by a specific field - 1\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 1)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {
                                                    switch (option) {
                                                        case 1: {
                                                            Scanner scInfo = new Scanner(System.in);
                                                            String info;

                                                            while (true) {
                                                                System.out.println("Go back - 0\n");

                                                                System.out.println("Filter services by seller username - 1");
                                                                System.out.println("Filter services by job name - 2");
                                                                System.out.println("Filter services by price range - 3\n");

                                                                System.out.print("Choose option: ");
                                                                option = Integer.parseInt(sc.nextLine());
                                                                clrscr();

                                                                if ((option < 0) || (option > 3)) {
                                                                    System.out.println("Wrong input!");
                                                                    try {
                                                                        Thread.sleep(2000);
                                                                    } catch (InterruptedException e) {
                                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                                    }
                                                                    clrscr();
                                                                }
                                                                else if (option != 0) {
                                                                    switch (option) {
                                                                        case 1: {
                                                                            System.out.print("Insert seller username: ");
                                                                            info = scInfo.nextLine();

                                                                            System.out.println();

                                                                            if (userService.getUserByUsername(info) == null) {
                                                                                System.out.println("There is no seller with the specified username!");

                                                                                System.out.println();
                                                                                pressEnterToContinue();

                                                                                clrscr();
                                                                                break;
                                                                            } else {
                                                                                List<Service> services = serviceService.filterServicesBySellerUsername(info);

                                                                                if (!services.isEmpty()) {
                                                                                    System.out.println("All of the stored services, filtered by the seller username \"" + info + "\":\n");

                                                                                    services.forEach( (service) -> { System.out.println(service); } );

                                                                                    System.out.println();
                                                                                    pressEnterToContinue();

                                                                                    clrscr();
                                                                                } else {
                                                                                    System.out.println("There are no services to print!");
                                                                                    try {
                                                                                        Thread.sleep(2000);
                                                                                    } catch (InterruptedException e) {
                                                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                                                    }
                                                                                    clrscr();
                                                                                }

                                                                                break;
                                                                            }
                                                                        }
                                                                        case 2: {
                                                                            System.out.print("Insert job name: ");
                                                                            info = scInfo.nextLine();

                                                                            System.out.println();

                                                                            if (jobService.getJobByName(info) == null) {
                                                                                System.out.println("There is no job with the specified name!");

                                                                                System.out.println();
                                                                                pressEnterToContinue();

                                                                                clrscr();
                                                                                break;
                                                                            } else {
                                                                                List<Service> services = serviceService.filterServicesByJobName(info);

                                                                                if (!services.isEmpty()) {
                                                                                    System.out.println("All of the stored services, filtered by the job name \"" + info + "\":\n");

                                                                                    services.forEach( (service) -> { System.out.println(service); } );

                                                                                    System.out.println();
                                                                                    pressEnterToContinue();

                                                                                    clrscr();
                                                                                } else {
                                                                                    System.out.println("There are no services to print!");
                                                                                    try {
                                                                                        Thread.sleep(2000);
                                                                                    } catch (InterruptedException e) {
                                                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                                                    }
                                                                                    clrscr();
                                                                                }

                                                                                break;
                                                                            }
                                                                        }
                                                                        case 3: {
                                                                            String[] priceRange;

                                                                            while (true) {
                                                                                System.out.print("Insert price range (of form: x - y): ");
                                                                                info = scInfo.nextLine();
                                                                                priceRange = info.split(" ");

                                                                                System.out.println();

                                                                                if (priceRange.length != 3) {
                                                                                    System.out.println("Invalid price range format!");
                                                                                    try {
                                                                                        Thread.sleep(2000);
                                                                                    } catch (InterruptedException e) {
                                                                                        System.out.println(e.getClass() + " " + e.getMessage());
                                                                                    }
                                                                                    clrscr();
                                                                                } else {
                                                                                    break;
                                                                                }
                                                                            }

                                                                            List<Service> services = serviceService.filterServicesByPriceRange(Double.parseDouble(priceRange[0]), Double.parseDouble(priceRange[2]));

                                                                            if (!services.isEmpty()) {
                                                                                System.out.println("All of the stored services, filtered by price range (" + info + "):\n");

                                                                                services.forEach( (service) -> { System.out.println(service); } );

                                                                                System.out.println();
                                                                                pressEnterToContinue();

                                                                                clrscr();
                                                                            } else {
                                                                                System.out.println("There are no services to print!");
                                                                                try {
                                                                                    Thread.sleep(2000);
                                                                                } catch (InterruptedException e) {
                                                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                                                }
                                                                                clrscr();
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    break;
                                                                }
                                                            }

                                                            break;
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                    case 3: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 0)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {

                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                    case 4: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 0)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {

                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                    case 5: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 0)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {

                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                    case 6: {
                                        while (true) {
                                            System.out.println("Go back - 0\n");

                                            System.out.print("Choose option: ");
                                            option = Integer.parseInt(sc.nextLine());
                                            clrscr();

                                            if ((option < 0) || (option > 0)) {
                                                System.out.println("Wrong input!");
                                                try {
                                                    Thread.sleep(2000);
                                                } catch (InterruptedException e) {
                                                    System.out.println(e.getClass() + " " + e.getMessage());
                                                }
                                                clrscr();
                                            } else {
                                                if (option != 0) {

                                                } else {
                                                    break;
                                                }
                                            }
                                        }

                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                    break;
                }
                case 10: {
                    continueNavigation = false;
                    System.out.println("Goodbye!");
                    try {
                        Thread.sleep(2200);
                    } catch(InterruptedException e) { System.out.println(e.getClass() + " " + e.getMessage()); }

                    break;
                }
                default: {
                    System.out.println("Wrong input!");
                    try {
                        Thread.sleep(2000);
                    } catch(InterruptedException e) { System.out.println(e.getClass() + " " + e.getMessage()); }
                    clrscr();
                }
            }
        }
    }
}
