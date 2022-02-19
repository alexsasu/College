using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class DeliveryAddressDTO
    {
        public int DeliveryAddressId { get; set; }
        public string Country { get; set; }
        public string City { get; set; }
        public string Street { get; set; }
        public int StreetNumber { get; set; }
        public int ClientId { get; set; }
        public string ClientName { get; set; }

        public DeliveryAddressDTO(DeliveryAddress deliv)
        {
            this.DeliveryAddressId = deliv.DeliveryAddressId;
            this.Country = deliv.Country;
            this.City = deliv.City;
            this.Street = deliv.Street;
            this.StreetNumber = deliv.StreetNumber;
            this.ClientId = deliv.Client.ClientId;
            this.ClientName = deliv.Client.ClientFirstName + " " + deliv.Client.ClientLastName;
        }
    }
}
