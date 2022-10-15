package model;

import java.sql.Date;

public final class BuyerHistory extends BuyerUtility {
    private String feedback;

    public BuyerHistory(Integer idService, Integer idBuyer, String type, Date serviceAddedDate, String feedback) {
        super(idService, idBuyer, type, serviceAddedDate);
        this.feedback = feedback;
    }

    public BuyerHistory(Integer idUtility, Integer idService, Integer idBuyer, String type, Date serviceAddedDate, String feedback) {
        super(idUtility, idService, idBuyer, type, serviceAddedDate);
        this.feedback = feedback;
    }

    public String getFeedback() {
        return feedback;
    }

    public void setFeedback(String feedback) {
        this.feedback = feedback;
    }

    @Override
    public String toString() {
        return super.toString() + " " +
                "BuyerHistory{" +
                "feedback='" + feedback + '\'' +
                '}';
    }
}
