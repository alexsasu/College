using asp_project.Models.Entities;
using asp_project.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.DeliveryAddressRepository
{
    public interface IDeliveryAddressRepository : IGenericRepository<DeliveryAddress>
    {
        Task<DeliveryAddress> GetDeliveryAddressByIdWithClient(int id);
        Task<List<DeliveryAddress>> GetAllDeliveryAddressesWithTheirClient();
    }
}
