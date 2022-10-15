using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class CreateClientDTO
    {
        public string ClientLastName { get; set; }
        public string ClientFirstName { get; set; }
        public DeliveryAddress DeliveryAddress { get; set; }
    }
}
