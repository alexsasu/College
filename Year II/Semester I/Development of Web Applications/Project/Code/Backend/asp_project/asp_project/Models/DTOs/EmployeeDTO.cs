using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class EmployeeDTO
    {
        public int EmployeeId { get; set; }
        public string Role { get; set; }
        public string EmployeeLastName { get; set; }
        public string EmployeeFirstName { get; set; }
        public double Salary { get; set; }
        public string PhoneNumber { get; set; }

        public EmployeeDTO(Employee emp)
        {
            this.EmployeeId = emp.EmployeeId;
            this.Role = emp.Role;
            this.EmployeeLastName = emp.EmployeeLastName;
            this.EmployeeFirstName = emp.EmployeeFirstName;
            this.Salary = emp.Salary;
            this.PhoneNumber = emp.PhoneNumber;
        }
    }
}
