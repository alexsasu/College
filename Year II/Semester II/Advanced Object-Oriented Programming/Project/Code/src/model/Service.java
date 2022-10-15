package model;

public final class Service {
    private Integer idService;
    private static Integer newIdService = 1;
    private Integer idSeller;
    private Integer idJob;
    private String description;
    private Double price;
//    private List<City> eligibleCities = new ArrayList<>();
    private String workSchedule;

    public Service(Integer idSeller, Integer idJob, String description, Double price, String workSchedule) {
        this.idService = Service.newIdService;
        this.idSeller = idSeller;
        this.idJob = idJob;
        this.description = description;
        this.price = price;
        this.workSchedule = workSchedule;

        ++newIdService;
    }

    public Service(Integer idService, Integer idSeller, Integer idJob, String description, Double price, String workSchedule) {
        this.idService = idService;
        this.idSeller = idSeller;
        this.idJob = idJob;
        this.description = description;
        this.price = price;
        this.workSchedule = workSchedule;

        if (idService >= newIdService) {
            newIdService = idService + 1;
        }
    }

    public Integer getIdService() {
        return idService;
    }

    public void setIdService(Integer idService) {
        this.idService = idService;
    }

    public static Integer getNewIdService() {
        return newIdService;
    }

    public static void setNewIdService(Integer newIdService) {
        Service.newIdService = newIdService;
    }

    public Integer getIdSeller() {
        return idSeller;
    }

    public void setIdSeller(Integer idSeller) {
        this.idSeller = idSeller;
    }

    public Integer getIdJob() {
        return idJob;
    }

    public void setIdJob(Integer idJob) {
        this.idJob = idJob;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public String getWorkSchedule() {
        return workSchedule;
    }

    public void setWorkSchedule(String workSchedule) {
        this.workSchedule = workSchedule;
    }

    @Override
    public String toString() {
        return "Service{" +
                "idService=" + idService +
                ", idSeller=" + idSeller +
                ", idJob=" + idJob +
                ", description='" + description + '\'' +
                ", price=" + price +
                ", workSchedule='" + workSchedule + '\'' +
                '}';
    }
}
