using asp_project.Models.Entities;
using asp_project.Models.DTOs;
using asp_project.Repositories.DeliveryAddressRepository;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.JsonPatch;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;

namespace asp_project.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DeliveryAddressController : ControllerBase
    {
        private readonly IDeliveryAddressRepository _repository;
        public DeliveryAddressController(IDeliveryAddressRepository repository)
        {
            _repository = repository;
        }


        [HttpPost]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> CreateDeliveryAddress(CreateDeliveryAddressDTO dto)
        {
            DeliveryAddress newDeliv = new DeliveryAddress();

            newDeliv.Country = dto.Country;
            newDeliv.City = dto.City;
            newDeliv.Street = dto.Street;
            newDeliv.StreetNumber = dto.StreetNumber;
            newDeliv.Client = dto.Client;

            _repository.Create(newDeliv);

            await _repository.SaveAsync();

            return Ok(new DeliveryAddressDTO(newDeliv));
        }


        [HttpGet("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetDeliveryAddressByIdWithClient(int id)
        {
            var deliv = await _repository.GetDeliveryAddressByIdWithClient(id);
            if (deliv == null)
            {
                return NotFound("The specified delivery address does not exist!");
            }

            return Ok(new DeliveryAddressDTO(deliv));
        }


        [HttpGet("getAllDeliveryAddressesWithTheirClient")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetAllDeliveryAddressesWithTheirClient()
        {
            var deliveryAddresses = await _repository.GetAllDeliveryAddressesWithTheirClient();

            var deliveryAddressesToReturn = new List<DeliveryAddressDTO>();
            foreach (var deliv in deliveryAddresses)
            {
                deliveryAddressesToReturn.Add(new DeliveryAddressDTO(deliv));
            }

            return Ok(deliveryAddressesToReturn);
        }


        [HttpPatch("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> PatchDeliveryAddress([FromRoute] int id, [FromBody] JsonPatchDocument<DeliveryAddress> deliv)
        {
            var delivToUpdate = await _repository.GetByIdAsync(id);
            if (delivToUpdate == null)
            {
                return NotFound("The specified delivery address does not exist!");
            }

            deliv.ApplyTo(delivToUpdate, ModelState);
            if (!ModelState.IsValid)
            {
                return BadRequest();
            }

            _repository.Update(delivToUpdate);

            await _repository.SaveAsync();

            return Ok(delivToUpdate);
        }


        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> DeleteDeliveryAddress(int id)
        {
            var deliv = await _repository.GetByIdAsync(id);
            if (deliv == null)
            {
                return NotFound("The specified delivery address does not exist!");
            }

            _repository.Delete(deliv);

            await _repository.SaveAsync();

            return NoContent();
        }
    }
}
