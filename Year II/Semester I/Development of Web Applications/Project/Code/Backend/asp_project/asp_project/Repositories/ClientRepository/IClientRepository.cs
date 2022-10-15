using asp_project.Models.Entities;
using asp_project.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.ClientRepository
{
    public interface IClientRepository : IGenericRepository<Client>
    {
        Task<Client> GetClientByIdWithDeliveryAddress(int id);
        Task<List<Client>> GetAllClientsWithTheirDeliveryAddress();
        Task<List<Component>> GetComponentsBought();
        Task UpdateClientPatchAsync(int id, Client cli);
    }
}

