using asp_project.Data;
using asp_project.Models.Entities;
using asp_project.Repositories;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Repositories.DeliveryAddressRepository
{
    public class DeliveryAddressRepository : GenericRepository<DeliveryAddress>, IDeliveryAddressRepository
    {
        public DeliveryAddressRepository(Context context) : base(context) { }

        public async Task<DeliveryAddress> GetDeliveryAddressByIdWithClient(int id)
        {
            return await _context.DeliveryAddresses.Include(deliv => deliv.Client).Where(deliv => deliv.DeliveryAddressId == id).FirstOrDefaultAsync();
        }

        public async Task<List<DeliveryAddress>> GetAllDeliveryAddressesWithTheirClient()
        {
            return await _context.DeliveryAddresses.Include(deliv => deliv.Client).ToListAsync();
        }
    }
}
