using asp_project.Data;
using asp_project.Models.Entities;
using asp_project.Repositories;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.ComponentRepository
{
    public class ComponentRepository : GenericRepository<Component>, IComponentRepository
    {
        public ComponentRepository(Context context) : base(context) { }

        public async Task<Component> GetComponentByIdWithClient(int id)
        {
            return await _context.Components.Include(comp => comp.Client).Where(comp => comp.ComponentId == id).FirstOrDefaultAsync();
        }

        public async Task<List<Component>> GetAllComponentsNotBoughtByClients()
        {
            return await _context.Components.Where(comp => comp.ClientId == 1).ToListAsync();
        }

        public async Task<List<Component>> GetAllComponentsBoughtByClients()
        {
            return await _context.Components.Include(comp => comp.Client).Where(comp => comp.ClientId != 1).ToListAsync();
        }

        public async Task<Client> GetClientById(int id)
        {
            return await _context.Clients.Include(cli => cli.Components).Where(cli => cli.ClientId == id).FirstOrDefaultAsync();
        }

        public async Task<List<Client>> GetClients()
        {
            return await _context.Clients.Where(cli => cli.ClientId != 1).ToListAsync();
        }
    }
}
