package model;

public final class City {
    private Integer idCity;
    private static Integer newIdCity = 1;
    private String name;

    public City(String name) {
        this.idCity = City.newIdCity;
        this.name = name;

        ++newIdCity;
    }

    public City(Integer idCity, String name) {
        this.idCity = idCity;
        this.name = name;

        if (idCity >= newIdCity) {
            newIdCity = idCity + 1;
        }
    }

    public Integer getIdCity() {
        return idCity;
    }

    public static Integer getNewIdCity() {
        return newIdCity;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "City{" +
                "idCity=" + idCity +
                ", name='" + name + '\'' +
                '}';
    }
}
