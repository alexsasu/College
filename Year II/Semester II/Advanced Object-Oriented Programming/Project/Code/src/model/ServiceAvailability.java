package model;

public class ServiceAvailability {
    private Integer idService;
    private Integer idCity;

    public ServiceAvailability(Integer idService, Integer idCity) {
        this.idService = idService;
        this.idCity = idCity;
    }

    public Integer getIdService() {
        return idService;
    }

    public void setIdService(Integer idService) {
        this.idService = idService;
    }

    public Integer getIdCity() {
        return idCity;
    }

    public void setIdCity(Integer idCity) {
        this.idCity = idCity;
    }

    @Override
    public String toString() {
        return "ServiceAvailability{" +
                "idService=" + idService +
                ", idCity=" + idCity +
                '}';
    }
}
