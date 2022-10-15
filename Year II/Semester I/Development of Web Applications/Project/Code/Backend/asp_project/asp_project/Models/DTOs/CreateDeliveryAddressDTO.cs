using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class CreateDeliveryAddressDTO
    {
        public string Country { get; set; }
        public string City { get; set; }
        public string Street { get; set; }
        public int StreetNumber { get; set; }
        public Client Client { get; set; }
    }
}
