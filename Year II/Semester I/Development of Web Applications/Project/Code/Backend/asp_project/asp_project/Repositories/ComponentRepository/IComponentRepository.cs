using asp_project.Models.Entities;
using asp_project.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.ComponentRepository
{
    public interface IComponentRepository : IGenericRepository<Component>
    {
        Task<Component> GetComponentByIdWithClient(int id);
        Task<List<Component>> GetAllComponentsNotBoughtByClients();
        Task<List<Component>> GetAllComponentsBoughtByClients();
        Task<Client> GetClientById(int id);
        Task<List<Client>> GetClients();
    }
}
