using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class ClientDTO
    {
        public int ClientId { get; set; }
        public string ClientLastName { get; set; }
        public string ClientFirstName { get; set; }
        public int DeliveryAddressId { get; set; }
        public string Country { get; set; }
        public string City { get; set; }
        public string Street { get; set; }
        public int StreetNumber { get; set; }

        public ClientDTO(Client cli)
        {
            this.ClientId = cli.ClientId;
            this.ClientLastName = cli.ClientLastName;
            this.ClientFirstName = cli.ClientFirstName;
            this.DeliveryAddressId = cli.DeliveryAddressId;
            this.Country = cli.DeliveryAddress.Country;
            this.City = cli.DeliveryAddress.City;
            this.Street = cli.DeliveryAddress.Street;
            this.StreetNumber = cli.DeliveryAddress.StreetNumber;
        }
    }
}
