package service;

import interfaces.ReportInterface;
import model.BuyerHistory;
import model.BuyerUtility;
import repository.BuyerUtilityRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class BuyerUtilityService implements ReportInterface {
    private static BuyerUtilityService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final BuyerUtilityRepository buyerUtilityRepository = new BuyerUtilityRepository();

    private final String fileName = "src/csvFiles/BuyersUtilities.csv";
//    private List<BuyerUtility> buyerUtilities = new ArrayList<>();

    private BuyerUtilityService() { }

    public static BuyerUtilityService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new BuyerUtilityService();
        }

        return INSTANCE;
    }

    public void addBuyerUtilityInfo(BuyerUtility buyerUtility) {
        buyerUtilityRepository.addBuyerUtilityInfo(buyerUtility);
    }

    public List<BuyerUtility> getBuyerUtilityById(Integer idUtility) {
        return buyerUtilityRepository.getBuyerUtilityById(idUtility);
    }

    public List<BuyerUtility> getAllBuyersUtilities() {
        return buyerUtilityRepository.getAllBuyersUtilities();
    }

    public void updateBuyerUtilityById(Integer idBuyerUtility, String field, String value) {
        buyerUtilityRepository.updateBuyerUtilityById(idBuyerUtility, field, value);
    }

    public void deleteBuyerUtilityById(Integer idUtility) {
        buyerUtilityRepository.deleteBuyerUtilityById(idUtility);
    }

//    public BuyerUtility getBuyerUtilityById(Integer idUtility) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (BuyerUtility buyerUtility : buyerUtilities) {
//                if (buyerUtility.getIdUtility().equals(idUtility)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return buyerUtilities.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public List<BuyerUtility> getBuyerUtilities() { return buyerUtilities; }
//
//    public void addBuyerUtilityInfo(BuyerUtility buyerUtility) {
//        buyerUtilities.add(buyerUtility);
//    }
//
//    public void updateBuyerUtilityById(Integer idUtility) {
//
//    }
//
//    public void deleteBuyerUtilityById(Integer idUtility) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (BuyerUtility buyerUtility : buyerUtilities) {
//                if (buyerUtility.getIdUtility().equals(idUtility)) {
//                    index = currentPosition;
//                }
//                ++currentPosition;
//            }
//            buyerUtilities.remove(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//        }
//    }

    @Override
    public void getReportInfo() {
        String[] buyerUtilities = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String buyerUtility : buyerUtilities) {
                String[] buyerUtilityInfo = buyerUtility.split(",");
                System.out.println(String.join(" | ", buyerUtilityInfo));
//                BuyerUtility buyerUtilityToBeAdded = new BuyerUtility(Integer.parseInt(buyerUtilityInfo[0]), buyerUtilityInfo[1], null);
//                this.buyerUtilities.add(buyerUtilityToBeAdded);
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

        List<BuyerUtility> buyerUtilities = getAllBuyersUtilities();

        String fileHeader = "Id,Service Id,Buyer Id,Type,Service Added Date,Feedback";
        writeService.writeToFile(fileName, fileHeader);
        for (BuyerUtility buyerUtility : buyerUtilities) {
            String buyerUtilityInfo =
                    buyerUtility.getIdUtility() + "," + buyerUtility.getIdService() + "," + buyerUtility.getIdBuyer() + "," +
                            buyerUtility.getType() + "," + buyerUtility.getServiceAddedDate();
            if (buyerUtility.getType().equalsIgnoreCase("history")) {
                buyerUtilityInfo += "," + ((BuyerHistory) buyerUtility).getFeedback();
            };

            writeService.writeToFile(fileName, buyerUtilityInfo);
        }
    }
}
