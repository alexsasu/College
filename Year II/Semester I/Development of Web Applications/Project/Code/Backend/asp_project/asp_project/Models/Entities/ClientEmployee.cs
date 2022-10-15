using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.Entities
{
    public class ClientEmployee
    {
        public int ClientId { get; set; }
        public int EmployeeId { get; set; }
        public Client Client { get; set; }
        public Employee Employee { get; set; }
    }
}
