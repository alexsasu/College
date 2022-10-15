package model;

public final class Seller extends User {
    private String description;
    private String phoneNumber;

    public Seller(String type, String firstName, String lastName, String username, String email, String password, String description, String phoneNumber) {
        super(type, firstName, lastName, username, email, password);
        this.description = description;
        this.phoneNumber = phoneNumber;
    }

    public Seller(Integer idSeller, String type, String firstName, String lastName, String username, String email, String password, String description, String phoneNumber) {
        super(idSeller, type, firstName, lastName, username, email, password);
        this.description = description;
        this.phoneNumber = phoneNumber;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String toString() {
        return super.toString() + " " +
                "Seller{" +
                "description='" + description + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                '}';
    }
}
