using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.Entities
{
    public class Employee
    {
        public int EmployeeId { get; set; }
        public string Role { get; set; }
        public string EmployeeLastName { get; set; }
        public string EmployeeFirstName { get; set; }
        public double Salary { get; set; }
        public string PhoneNumber { get; set; }
        public ICollection<ClientEmployee> ClientEmployees { get; set; }
    }
}
