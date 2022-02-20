using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.Entities
{
    public class Client
    {
        public int ClientId { get; set; }
        public string ClientLastName { get; set; }
        public string ClientFirstName { get; set; }
        public int DeliveryAddressId { get; set; }
        public DeliveryAddress DeliveryAddress { get; set; }
        public ICollection<Component> Components { get; set; }
        public ICollection<ClientEmployee> ClientEmployees { get; set; }
    }
}
