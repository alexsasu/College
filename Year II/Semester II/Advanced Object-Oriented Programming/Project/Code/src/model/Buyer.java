package model;

import java.util.List;

public final class Buyer extends User {
    public Buyer(String type, String firstName, String lastName, String username, String email, String password) {
        super(type, firstName, lastName, username, email, password);
    }

    public Buyer(Integer idBuyer, String type, String firstName, String lastName, String username, String email, String password) {
        super(idBuyer, type, firstName, lastName, username, email, password);
    }
}
