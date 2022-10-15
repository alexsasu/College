package model;

public final class Job {
    private Integer idJob;
    private static Integer newIdJob = 1;
    private String name;

    public Job(String name) {
        this.idJob = newIdJob;
        this.name = name;

        ++newIdJob;
    }

    public Job(Integer idJob, String name) {
        this.idJob = idJob;
        this.name = name;

        if (idJob >= newIdJob) {
            newIdJob = idJob + 1;
        }
    }

    public Integer getIdJob() {
        return idJob;
    }

    public static Integer getNewIdJob() {
        return newIdJob;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Job{" +
                "idJob=" + idJob +
                ", name='" + name + '\'' +
                '}';
    }
}
