package model;

import java.sql.Date;

public class BuyerUtility {
    private Integer idUtility;
    private static Integer newIdUtility = 1;
    private Integer idService;
    private Integer idBuyer;
    private String type;
    private Date serviceAddedDate;

    public BuyerUtility(Integer idService, Integer idBuyer, String type, Date serviceAddedDate) {
        this.idUtility = BuyerUtility.newIdUtility;
        this.idService = idService;
        this.idBuyer = idBuyer;
        this.type = type;
        this.serviceAddedDate = serviceAddedDate;

        ++newIdUtility;
    }

    public BuyerUtility(Integer idUtility, Integer idService, Integer idBuyer, String type, Date serviceAddedDate) {
        this.idUtility = idUtility;
        this.idService = idService;
        this.idBuyer = idBuyer;
        this.type = type;
        this.serviceAddedDate = serviceAddedDate;

        if (idUtility >= newIdUtility) {
            newIdUtility = idUtility + 1;
        }
    }

    public Integer getIdUtility() {
        return idUtility;
    }

    public void setIdUtility(Integer idUtility) {
        this.idUtility = idUtility;
    }

    public static Integer getNewIdUtility() {
        return newIdUtility;
    }

    public static void setNewIdUtility(Integer newIdUtility) {
        BuyerUtility.newIdUtility = newIdUtility;
    }

    public Integer getIdService() {
        return idService;
    }

    public void setIdService(Integer idService) {
        this.idService = idService;
    }

    public Integer getIdBuyer() {
        return idBuyer;
    }

    public void setIdBuyer(Integer idBuyer) {
        this.idBuyer = idBuyer;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Date getServiceAddedDate() {
        return serviceAddedDate;
    }

    public void setServiceAddedDate(Date serviceAddedDate) {
        this.serviceAddedDate = serviceAddedDate;
    }

    @Override
    public String toString() {
        return "BuyerUtility{" +
                "idUtility=" + idUtility +
                ", idService=" + idService +
                ", idBuyer=" + idBuyer +
                ", type='" + type + '\'' +
                ", serviceAddedDate=" + serviceAddedDate +
                '}';
    }
}
