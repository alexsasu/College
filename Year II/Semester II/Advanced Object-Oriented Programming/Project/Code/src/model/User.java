package model;

public abstract class User {
    private Integer idUser;
    private static Integer newIdUser = 1;
    private String type;
    private String firstName;
    private String lastName;
    private String username;
    private String email;
    private String password;
//    private List<Language> languages = new ArrayList<>();

    public User(String type, String firstName, String lastName, String username, String email, String password) {
        this.idUser = User.newIdUser;
        this.type = type;
        this.firstName = firstName;
        this.lastName = lastName;
        this.username = username;
        this.email = email;
        this.password = password;

        ++newIdUser;
    }

    public User(Integer idUser, String type, String firstName, String lastName, String username, String email, String password) {
        this.idUser = idUser;
        this.type = type;
        this.firstName = firstName;
        this.lastName = lastName;
        this.username = username;
        this.email = email;
        this.password = password;

        if (idUser >= newIdUser) {
            newIdUser = idUser + 1;
        }
    }

    public Integer getIdUser() {
        return idUser;
    }

    public void setIdUser(Integer idUser) {
        this.idUser = idUser;
    }

    public static Integer getNewIdUser() {
        return newIdUser;
    }

    public static void setNewIdUser(Integer newIdUser) {
        User.newIdUser = newIdUser;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    //    public List<Language> getLanguages() {
//        return languages;
//    }
//
//    public void setLanguages(List<Language> languages) {
//        this.languages = languages;
//    }

    @Override
    public String toString() {
        return "User{" +
                "idUser=" + idUser +
                ", type='" + type + '\'' +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", username='" + username + '\'' +
                ", email='" + email + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
