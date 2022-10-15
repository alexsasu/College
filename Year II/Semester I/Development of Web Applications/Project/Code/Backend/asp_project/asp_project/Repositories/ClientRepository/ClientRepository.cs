using asp_project.Data;
using asp_project.Models.Entities;
using asp_project.Repositories;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.ClientRepository
{
    public class ClientRepository : GenericRepository<Client>, IClientRepository
    {
        public ClientRepository(Context context) : base(context) { }

        public async Task<Client> GetClientByIdWithDeliveryAddress(int id)
        {
            return await _context.Clients.Include(cli => cli.DeliveryAddress).Where(cli => cli.ClientId == id).FirstOrDefaultAsync();
        }

        public async Task<List<Client>> GetAllClientsWithTheirDeliveryAddress()
        {
            return await _context.Clients.Include(cli => cli.DeliveryAddress).ToListAsync();
        }

        public async Task<List<Component>> GetComponentsBought()
        {
            return await _context.Components.Where(comp => comp.ClientId != 1).ToListAsync();
        }

        public async Task UpdateClientPatchAsync(int id, Client cli)
        {
            _context.Clients.Update(cli);
            await _context.SaveChangesAsync();
        }
    }
}
